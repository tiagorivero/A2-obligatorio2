#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//Codigo tomado de la clase del 13/11
int mochila(int n, int cap, int* pesos, int* satisfacciones, int* categorias, int* limCategoria) {
    int****** tab = new int*****[n + 1]();
    for (int i = 0; i <= n; i++){
        tab[i] = new int****[cap + 1]();
        for (int j = 0; j <= cap; j++){
            tab[i][j] = new int***[limCategoria[0] + 1]();
            for (int k = 0; k <= limCategoria[0]; k++){
                tab[i][j][k] = new int**[limCategoria[1] + 1]();
                for (int l = 0; l <= limCategoria[1]; l++){
                    tab[i][j][k][l] = new int*[limCategoria[2] + 1]();
                    for (int w = 0; w <= limCategoria[2]; w++){
                        tab[i][j][k][l][w] = new int[limCategoria[3] + 1]();
                    }
                }
            }
        }
    }
    
    for (int obj = 1; obj <= n; obj++) {
        int peso_obj = pesos[obj];
        int satisfaccion_obj = satisfacciones[obj];
        int categoria_obj = categorias[obj];
        
        for (int cap_i = 0; cap_i <= cap; cap_i++) {
            for (int L0_i = 0; L0_i <= limCategoria[0]; L0_i++) {
                for (int L1_i = 0; L1_i <= limCategoria[1]; L1_i++) {
                    for (int L2_i = 0; L2_i <= limCategoria[2]; L2_i++) {
                        for (int L3_i = 0; L3_i <= limCategoria[0]; L3_i++) {
                            int limite = L0_i;
                            if(categoria_obj == 1) limite = L1_i;
                            if(categoria_obj == 2) limite = L2_i;
                            if(categoria_obj == 3) limite = L3_i;

                            if (peso_obj > cap_i || (limite < 1))
                                tab[obj][cap_i][L0_i][L1_i][L2_i][L3_i] = tab[obj - 1][cap_i][L0_i][L1_i][L2_i][L3_i];
                            else
                                tab[obj][cap_i][L0_i][L1_i][L2_i][L3_i] = max(tab[obj - 1][cap_i][L0_i][L1_i][L2_i][L3_i], satisfaccion_obj + tab[obj - 1][cap_i - peso_obj][L0_i][L1_i][L2_i][L3_i]);
                        }
                    }
                }
            }
        }
    } 
    return tab[n][cap][limCategoria[0]][limCategoria[1]][limCategoria[2]][limCategoria[3]]; 
}
//

int main()
{
    int N, W;
    cin >> N >> W;

    int* limCategoria = new int[4];
    cin >> limCategoria[0] >> limCategoria[1] >> limCategoria[2] >> limCategoria[3];

    int* pesos = new int[N];
    int* satisfacciones = new int[N];
    int* categorias = new int[N];

    for(int i = 0; i < N; i++){
        int peso, satisfaccion, categoria;
        cin >> peso >> satisfaccion >> categoria;
        pesos[i] = peso;
        satisfacciones[i] = satisfaccion; 
        categorias[i] = categoria;
    }
    
    int maxSatisfaccion = mochila(N,W,pesos,satisfacciones,categorias,limCategoria);
    cout << maxSatisfaccion << endl;

    return 0;
}
// la mochila fue tomada de la clase del 13/11, yo adapte el codigo al ejercicio ademas de recibir ayuda de claude para las explicaciones y depuraciones
#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int maximo(int a, int b){
    return (a > b) ? a : b;
}

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
                        for (int L3_i = 0; L3_i <= limCategoria[3]; L3_i++) {
                            int limitesDisponibles[4] = {L0_i,L1_i,L2_i,L3_i};

                            if (peso_obj > cap_i || (limitesDisponibles[categoria_obj] < 1))
                                tab[obj][cap_i][L0_i][L1_i][L2_i][L3_i] = tab[obj - 1][cap_i][L0_i][L1_i][L2_i][L3_i];
                            else{
                                limitesDisponibles[categoria_obj]--;
                                tab[obj][cap_i][L0_i][L1_i][L2_i][L3_i] = maximo(tab[obj - 1][cap_i][L0_i][L1_i][L2_i][L3_i], satisfaccion_obj + tab[obj - 1][cap_i - peso_obj][limitesDisponibles[0]][limitesDisponibles[1]][limitesDisponibles[2]][limitesDisponibles[3]]);
                            }
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

    int* pesos = new int[N + 1];
    int* satisfacciones = new int[N + 1];
    int* categorias = new int[N + 1];

    for(int i = 1; i < N + 1; i++){
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
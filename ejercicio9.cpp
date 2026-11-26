//codigo hecho por mi basado en el dibujo de clase ademas de utilizar el ejemplo de Fibonacci para la memoizacion, ademas de ser ayudado por claude para las explicaciones y depurar.
#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int maximo(int a, int b){
    return (a > b) ? a : b;
}

int decidirBailar(int r, int d, int b, int cantRondas, int* mete, int* likes, int*** memo){
    if(r == cantRondas){
        return 0;
    }

    if (memo[r][d][b] != -1) return memo[r][d][b];

    int d_n = d + mete[r];

    int resultado;
    if(d_n > 0){
        int likesBaile = likes[r];
        if(b == 1) likesBaile = likes[r] / 2;

        int likesSiBaila = likesBaile + decidirBailar(r + 1, d_n - 1, 1, cantRondas, mete, likes, memo);
        int likesSiAtaja = decidirBailar(r + 1, d_n, 0, cantRondas, mete, likes, memo);
        
        resultado = maximo(likesSiAtaja, likesSiBaila);
    } else{
        resultado = decidirBailar(r + 1, d_n, 0, cantRondas, mete, likes, memo);
    }

    memo[r][d][b] = resultado;
    return resultado;
}

int main()
{
    int K;
    cin >> K;

    int* mete = new int[K];
    int* likes = new int[K];

    for(int i = 0; i < K; i++){
        int anotacion;
        cin >> anotacion;
        mete[i] = anotacion;
    }

    for(int i = 0; i < K; i++){
        int like;
        cin >> like;
        likes[i] = like;
    }

    int*** memo = new int**[K]();
    for (int i = 0; i < K; i++){
        memo[i] = new int*[K + 1]();
        for (int j = 0; j <= K; j++){
            memo[i][j] = new int[2]();
            for (int k = 0; k < 2; k++){
                memo[i][j][k] = -1;
            }
        }
    }

    int resultado = decidirBailar(0, 0, 0, K, mete, likes, memo);
    cout << resultado << endl;

    delete[] mete;
    delete[] likes;

    return 0;
}
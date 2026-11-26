#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int letrasValores[26];
bool digitosUsados[10];
int cantLetrasAsignadas;

int cantPalabras;
string palabras[6];

bool esSolucion(int i) {
    int suma = 0;
    for (int i = 0; i < cantPalabras - 1; i++){
        for (int j = 0; j < palabras[i].length(); j++)
        {
            suma += letrasValores[palabras[i][j] - 'A'];
        }
    }
    int resultado = 0;
    string ultimaPalabra = palabras[cantPalabras - 1];
    for (int j = 0; j < ultimaPalabra.length(); j++) {
        resultado = letrasValores[ultimaPalabra[j] - 'A'];
    }
    return cantLetrasAsignadas == i && suma == resultado;
}

bool puedoAplicarMovimiento(int digito) {
    return !digitosUsados[digito];
}

void aplicarMovimiento(int letra, int digito) {
    letrasValores[letra] = digito;
    digitosUsados[digito] = true;
}

void deshacerMovimiento(int letra, int digito) {
    letrasValores[letra] = -1;
    digitosUsados[digito] = false;
}

bool esMejorSolucion(int pasosActual, int mejorPasos) {
    return pasosActual < mejorPasos;
}

void clonarSolucion(int** actual, int**& destino) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = actual[i][j];
        }
    }
}

bool puedoPodar(int pasoActual, int mejorPasos) {
    return pasoActual >= mejorPasos;
}

// Optimización: si ya encontré una solución, no busco más
void caballo_opt(int pasoActual, Coordenada actual, Coordenada destino, int** camino, int**&mejorCamino, int &mejorPasos) {
    if(!puedoPodar(pasoActual, mejorPasos)) {
        if (esSolucion(actual, destino) && esMejorSolucion(pasoActual, mejorPasos)) {
            clonarSolucion(camino, mejorCamino);
            mejorPasos = pasoActual;
        } else {
            int df[8] = { -1, -2, -2, -1, 1, 2,  2,  1 };
            int dc[8] = { -2, -1,  1,  2, 2, 1, -1, -2 };
            for (int m = 0; m < 8; m++) {
                Coordenada prox(actual.fila + df[m], actual.col + dc[m]);
                if (puedoAplicarMovimiento(prox, camino)) { // sandwich: va todo junto
                    aplicarMovimiento(prox, camino, pasoActual + 1);   // marcar
                    caballo_opt(pasoActual + 1, prox, destino, camino, mejorCamino,mejorPasos); // recursión
                    deshacerMovimiento(prox, camino);                   // backtracking
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int K;
        cin >> K;
        cantPalabras = K + 1;

        for(int i = 0; i < K + 1; i++){
            cin >> palabras[i];
        } 

        for(int i = 0; i < 26; i++){
            letrasValores[i] = -1;
        }
        for(int j = 0; j < 10; j++){
            digitosUsados[j] = false;
        }
        
    }

    return 0;
}
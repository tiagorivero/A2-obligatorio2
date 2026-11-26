// Tome como base la implementacion de caballo_opt, luego me ayude con claude para que me diera ideas en la implementacion de ciertas funciones que luego yo pase a codigo y luego me ayudo a depurar.
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

bool iniciales[26]; 
long long mejores[6];
int cantidadColumnas;
int letrasOrdenadas[10];
bool existeSolucion;

bool esSolucion(int i) {
    return i == cantLetrasAsignadas;
}

bool puedoAplicarMovimiento(int letra, int digito) {
    return !digitosUsados[digito] && !(digito == 0 && iniciales[letra]);
}

void aplicarMovimiento(int letra, int digito) {
    letrasValores[letra] = digito;
    digitosUsados[digito] = true;
}

void deshacerMovimiento(int letra, int digito) {
    letrasValores[letra] = -1;
    digitosUsados[digito] = false;
}

bool esMejorSolucion() {
    if (!existeSolucion) return true;
    long long res = 0;
    string ultimaPalabra = palabras[cantPalabras - 1];
    for (int i = 0; i < ultimaPalabra.length(); i++) {
        res = res*10 + letrasValores[ultimaPalabra[i] - 'A'];
    }

    if(res != mejores[cantPalabras - 1]){
        return res < mejores[cantPalabras - 1];
    }

    for(int i = 0; i < cantPalabras - 1; i++){
        long long sumando = 0;
        for (int j = 0; j < palabras[i].length(); j++) {
            sumando = sumando*10 + letrasValores[palabras[i][j] - 'A'];
        }

        if(sumando != mejores[i]){
            return sumando < mejores[i];
        }
    }
    return false;
}

void clonarSolucion() {
    existeSolucion = true;
    for(int i = 0; i < cantPalabras; i++){
        long long mejor = 0;
        for (int j = 0; j < palabras[i].length(); j++){
            mejor = mejor*10 + letrasValores[palabras[i][j] - 'A'];
        }
        mejores[i] = mejor;
    }
}

bool puedoPodar() {
    if (existeSolucion) {
        string resultado = palabras[cantPalabras - 1];
        long long resValor = 0;
        for (int i = 0; i < resultado.length(); i++) {
            int letra = resultado[i] - 'A';
            if (letrasValores[letra] == -1) {
                if (iniciales[letra]) {
                    resValor = resValor*10 + 1;
                } else {
                    resValor = resValor*10;
                }
            } else {
                resValor = resValor*10 + letrasValores[letra];
            }
        }
        if (resValor > mejores[cantPalabras - 1]) {
            return true;
        }
    }

    int acarreo = 0;
    for(int col = 0; col < cantidadColumnas; col++){
        int suma = acarreo;

        for(int i = 0; i < cantPalabras - 1; i++){
            int largo = palabras[i].length();
            if (col < largo) {
                int letra = palabras[i][largo - 1 - col] - 'A';
                if(letrasValores[letra] == -1){
                    return false;
                } 
                suma += letrasValores[letra];
            }
        }

        int resultadoFinal = 0;
        string res = palabras[cantPalabras - 1];
        if (col < res.length()){
            int letra = res[res.length() - 1 - col] - 'A';
            if(letrasValores[letra] == -1){
                return false;
            } 
            resultadoFinal = letrasValores[letra];
        }

        if(suma % 10 != resultadoFinal){
            return true;
        }
        acarreo = suma / 10;
    }
    return acarreo != 0;
}

// template tomado del teorico de la clase
void criptoaritmetica_opt(int i) {
    if(!puedoPodar()) {
        if (esSolucion(i)) {
            if(esMejorSolucion()){
                clonarSolucion();
            }
        } else {
            int letra = letrasOrdenadas[i];
            for (int digito = 0; digito < 10; digito++){
                if(puedoAplicarMovimiento(letra, digito)){
                    aplicarMovimiento(letra, digito);
                    criptoaritmetica_opt(i + 1);
                    deshacerMovimiento(letra, digito);
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
            iniciales[i] = false;
        }
        for(int j = 0; j < 10; j++){
            digitosUsados[j] = false;
        }
        existeSolucion = false;
        
        cantidadColumnas = 0;
        for(int i = 0; i < cantPalabras; i++){
            if(palabras[i].length() > cantidadColumnas){
                cantidadColumnas = palabras[i].length();
            }
            if(palabras[i].length() > 1){
                iniciales[palabras[i][0] - 'A'] = true;
            }
        }

        cantLetrasAsignadas = 0;
        bool agregadas[26];
        for(int i = 0; i < 26; i++) agregadas[i] = false;

        for(int col = 0; col < cantidadColumnas; col++){
            for(int i = 0; i < cantPalabras; i++){
                int largo = palabras[i].length();
                if (col<largo){
                    int letra = palabras[i][largo - 1 - col] - 'A';
                    if(!agregadas[letra]){
                        agregadas[letra] = true;
                        letrasOrdenadas[cantLetrasAsignadas] = letra;
                        cantLetrasAsignadas++;
                    }
                }
            }
        }

        criptoaritmetica_opt(0);

        if(!existeSolucion){
            cout << "imposible" << endl;
        } else {
            for(int i = 0; i < cantPalabras - 1; i++){
                if(i > 0){
                    cout << " + ";
                }
                cout << mejores[i];
            }
            cout << " = " << mejores[cantPalabras - 1] << endl;
        }
    }

    return 0;
}
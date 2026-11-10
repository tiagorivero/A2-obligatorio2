// La implementacion fue hecha por mi, la ia solo depuro, detectando errores que yo arregle.
#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int* conteo = new int[1001]();
    int* resultado = new int[N];
    int pos = 0;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        conteo[num]++;
    }

    int mayorSolo = -1;
    for(int i = 1000; i >= 0; i--){
        while(conteo[i] > 1){
            resultado[pos] = i;
            pos++;
            conteo[i] -= 2;
        }
        if(conteo[i] == 1 && i > mayorSolo){
            mayorSolo = i;
        }
    }

    bool primero = true;
    for(int i = 0; i < pos; i++){
        if(!primero) cout << " ";
        cout << resultado[i];
        primero = false;
    }
    if(mayorSolo != -1){
        if(!primero) cout << " ";
        cout << mayorSolo;
        primero = false;
    }
    for(int i = pos - 1; i >= 0; i--){
        if(!primero) cout << " ";
        cout << resultado[i];
        primero = false;
    }

    cout << endl;

    delete[] conteo;
    delete[] resultado;

    return 0;
}
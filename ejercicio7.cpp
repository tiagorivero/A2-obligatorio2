#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

// Tomado del teorico de Dividir y Conquistar dado en la clase del 28/11 y corregido por mi depurando con claude
int* intercalar(int arr1[], int n1, int arr2[], int n2) {
  int* ret = new int[n1 + n2];

  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      ret[k++] = arr1[i++];
    } else {
      ret[k++] = arr2[j++];
    }
  }

  while (i < n1) {
    ret[k++] = arr1[i++];
  }

  while (j < n2) {
    ret[k++] = arr2[j++];
  }

  return ret;
}

int* mergeSort(int valores[], int inicio, int fin, long long& cantRemontadasEpicas){
  if(inicio == fin){
    int* ret = new int[1];
    ret[0] = valores[inicio];
    return ret;
  }

  int mitad = (inicio + fin) / 2;

  int* ord1 = mergeSort(valores, inicio, mitad, cantRemontadasEpicas);
  int* ord2 = mergeSort(valores, mitad + 1, fin, cantRemontadasEpicas);

  int n1 = mitad - inicio + 1;
  int n2 = fin - mitad;

  int i = 0;
  int j = 0;
  while(i < n1 && j < n2){
    if(ord1[i] > ord2[j]*2){
      cantRemontadasEpicas += n1 - i;
      j++;
    }else{
      i++;
    }
  }

  int* ret = intercalar(ord1, n1, ord2, n2);
  delete[] ord1;
  delete[] ord2;
  return ret;
}
//

int main()
{
    int N;
    cin >> N;

    long long cantRemontadasEpicas = 0;
    int* posCorredores = new int[N];

    for(int i = 0; i < N; i++){
        int corredor;
        cin >> corredor;
        posCorredores[i] = corredor;
    }

    int* ordenado = mergeSort(posCorredores,0,N-1,cantRemontadasEpicas);

    cout << cantRemontadasEpicas << endl;

    delete[] ordenado;
    delete[] posCorredores;

    return 0;
}
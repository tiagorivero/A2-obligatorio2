# Justificación de órdenes — Obligatorio 2

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 6
- La letra pedia greedy en O(N) de tiempo y espacio. Como los numeros van de 0 a 1000 lo que 
hago es poner las placas de cada numero en un arreglo de 1001 en O(N), luego recorro los 
valores de mayor a menor y con un while voy sacando de a pares y guardando en el resultado, asi 
los más grandes quedan en los extremos y el mayor que sobra va en el centro. Como son 1001 
elementos y el while hace como mucho N/2 iteraciones en total ya que cada una saca un par, 
termina quedando en O(N). Luego Imprimir las dos mitados y el centro es O(N).
- El conteo tiene un tamaño fijo y el resultado ocupa N, quedando O(N) de espacio.

## Ejercicio 7
- La letra pedía dividir y conquistar en O(N log N) de tiempo y O(N) de espacio. Uso un mergesort 
que divide el array a la mitad hasta llegar a un solo corredor y al combinar antes de intercalar, 
cuento las remontadas entre las dos mitades. Como las mitades ya vienen ordenadas, cuando ord1[i] 
le gana a ord2[j] también le ganan todos los que siguen, así que sumo n1 - i, los índices i y j 
solo avanzan, por lo que contar y intercalar es O(N) en cada combinación. Son log N niveles con N 
elementos en total por nivel, quedando O(N log N). 
- Los arrays auxiliares se liberan después de intercalar, así que en cada momento solo estan los 
del camino de la recursión, que suman O(N). El contador es long long porque puede superar 32 bits.

## Ejercicio 8
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 9
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...


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
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 8
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 9
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...


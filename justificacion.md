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
- La letra pedía programación dinámica con tabulación en O(N·W·L0·L1·L2·L3) de tiempo y espacio. Uso la mochila 0/1 vista  
en clase pero con una tabla de 6 dimensiones con objetos, peso y los 4 limites por cada categoria. Cada celda guarda la 
mejor satisfaccion con esos objetos, ese peso y esos 4 lugares por categoria, y se calcula en O(1) con el maximo entre no 
llevar el objeto osea tomar la celda de arriba o llevarlo si entra en peso y queda lugar en su categoria, osea su 
satisfaccion más la celda de arriba con menos peso y un lugar menos en su categoria. 
- Recorro todas las celdas con 6 for anidados, que son N·W·L0·L1·L2·L3 celdas, quedando ese orden de tiempo, y la tabla 
ocupa lo mismo en espacio.

## Ejercicio 9
- La letra pedía programación dinámica con memoización en O(K^2) de tiempo y espacio. Lo que hago 
es usar funcion recursiva con el estado (r, d, b) que seria la ronda, la diferencia de goles de A 
y si bailo en el tiro anterior, basandome en el diagrama hecho en clase, en cada ronda patea A y 
calculo la nueva diferencia d_n y si es mayor a 0, puede elegir si atajar o bailar con la mitad 
de likes si ya habia bailado anteriormente, entre estas 2 opciones me quedo con el maximo, si no 
solo puede atajar.
- Luego guardo cada estado en memo de K*(K+1)*2 inicializado en -1, asi cada estado se calcula 
una sola vez en O(1), quedando O(K^2) de tiempo, y el memo ocupa O(K^2) de espacio.

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...


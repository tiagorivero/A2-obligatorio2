# Bitácora — Obligatorio 2

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-11-03 — Tiago Rivero
- Primero lo que hice fue usar como template el repositorio de github, crear el mio y clonarlo 
en mi pc.
- Luego lei la letra del ejercicio 6.
- Empece a pensar ideas de como resolver el ejercicio sin tocar codigo , inicialmente pense que 
podria ir tomando los maximos y ir escribiendolos en un string resultado y mostrarlo.

## 2026-11-05 — Tiago Rivero
- Invite al profesor para ser colaborador en mi respositorio de github.
- Empece a escribir el codigo del ejercicio 6 en la que me di cuenta que mi idea inicial de 
tomar los maximos no iba a servir ya que necesitaba ir verificando si cada maximo tenia una 
cantidad mayor a 1. 
- Para lo cual pense en hacer un array conteo con 1001 posiciones ya que los numeros grabados 
solo toman valores entre 0 y 1000.

(Esta primer version no la comitie porque no estaba terminada, desde ahora en adelante hago 
commit por más minimo cambio que haya en el codigo)

## 2026-11-10 — Tiago Rivero
- Continue con el ejercicio, ya con el array conteo lo recorro desde 1000 hasta 0 y en cada 
posicion mientras que esta aparezca más de una vez lo agrego a mi array resultado, avanzo la 
posicion y resto 2 por el par. Y si todavia me quedaba uno y este es mayor que el maximo lo 
guardo para ponerlo al medio.
- Luego recorro el resultado mostrando los elementos hasta la ultima posicion que se inserto, 
muestro el medio y vuelvo a recorrer pero desde la ultima posicion hasta la primera.
- Corri las pruebas y estas me dieron errores, para lo que depure con claude algunos bugs 
chicos como condiciones de los for al revés o imprimir mal el resultado. Ademas la letra pedia 
un unico espacio entre los numeros y ami me quedaba siempre uno de más para lo cual inserto el
espacio antes solo sino es el primero.
- Luego las pruebas pasaron correctamente
- Commitie el ejercicio 6

- Para la funcion que corre todas las pruebas reutilice la misma del obligatorio 1 que fue 
generada por IA. chat: "https://claude.ai/share/642800ad-095a-4bbc-bfb5-32a8286454af".

## 2026-11-12 — Tiago Rivero
- Lei la letra del ejercicio 7. Ademas volvi a ver la clase del 28/10 donde el profesor explico 
este ejercicio. 
- En esta clase se explica que este ejercicio es un mergesort que al combinar, primero cuenta las 
remontadas entre las dos mitades y después las ordena. Ademas dimos un codigo de mergesort el 
cual es el mismo que voy a utilizar como base.
- En el main simplemente tomo la cantidad de corredores y los guardo en un array y llamo al 
mergesort que mediante el & para la direccion de memoria va cambiando la cantidad de remontadas.
- Ademas en la letra se menciona que la cantidad de remontadas épicas puede superar el rango de 
un entero de 32 bits para lo que utilice long long.
- En el mergesort basandome en el ejemplo de clase, mi idea inicial es usar un indice en cada 
mitad, si el elemento de la primera mitad es mayor que el doble del de la segunda, avanzo el 
indice de la segunda si no, avanzo el de la primera y vuelvo a poner en 0 el de la segunda.
- En la funcion mientras que el elemento de ambas mitadades con su indice no sea nulo hago la 
comparacion de arriba si la primera mitad es mayor que el doble sumo una remontada y avanzo j, 
sino avanzo i para ir al siguiente de la primera mitad y reinicio el j para empezar de nuevo.
- La funcion de intercalar por ahora la dejo igual porque entiendo que solo ordena las mitades.
- Commiteo lo que avance hoy del ejercicio 7 
(arregle la linea de la bitacora del 2026-11-10 que llame al ejercicio 6 como ejercicio 1)

## 2026-11-13 — Tiago Rivero
- Continue con el ejercicio que quedo a medias ayer, probe las pruebas y estas me dieron errores 
para lo que le pedi a claude que depurara mi codigo.
- Claude noto varios errores en el codigo, como la funcion intercalar que usa sizeof y daba 
error, ya que cuando pasas un array a una funcion se convierte en un puntero y termina dando el 
tamaño del puntero y no el del array, error mio por tomar directamente el codigo del teorico y no 
verificar si me servia, para lo cual tuve que cambiar la logia de como la funcion recibe los 
tamaños. Para esto le paso los tamaños al llamarla en vez de calcularlos con sizeof.
- Otro error bastante principal que me marco fue el while en el que la condicion miraba los 
valores y no si los indices se salian de los arrays, la comparacion estaba invertida y reiniciaba 
el j en 0 lo que hacia que no cumpliera el orden que pedia el ejercicio.
- Para arreglar este bucle cambié la condición para que compare los índices con el tamaño de cada
mitad, di vuelta la comparación y saqué el reinicio de j: si había remontada sumaba 1 y avanzaba 
j, y si no avanzaba i, así ninguno de los dos índices vuelve atrás.
- Y tambien otros errore más simples como tomar el fin del arreglo como N en vez de N-1, no haber 
inicializado el contador, o no manejar las perdidas de memoria
- Volvi a depurar con claude y esta versión todavía tenia algunos errores, no controlaba la 
memoria correctamente y contaba de menos, porque cuando ord1[i] le gana a ord2[j] también le 
ganan todos los que siguen en la primera mitad ya que está ordenada. Esto lo arregle calculando 
la distancia con el resto osea sumando n1 - i en vez de 1.
- Commitie el ejercicio 7
(arregle la fecha de la clase de vi que estaba mal en bitacora y autoria, era 28/10 no 28/11)
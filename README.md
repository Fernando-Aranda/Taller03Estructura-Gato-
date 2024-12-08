## Juego de Gato con Inteligencia Artificial
Este repositorio contiene el código para simular el juego clásico de Gato (Tic-Tac-Toe)
con una implementación de inteligencia artificial (IA) para jugar contra un humano. A continuación, se describe el algoritmo utilizado, ejemplos prácticos, análisis de casos simples y la explicación de la búsqueda en el árbol de juego.

---
## Breve Explicación Teórica del Algoritmo
El juego de Gato es un juego de dos jugadores en un tablero de 3x3 casillas. 
Los jugadores alternan turnos para colocar sus símbolos (X u O) en las casillas vacías, con el objetivo de alinear tres símbolos en línea (horizontal, vertical o diagonal). Si uno de los jugadores alinea tres símbolos, gana el juego.

Este programa simula el juego en una consola, permitiendo tanto un modo multijugador 
como un modo IA. En el modo IA, la Inteligencia Artificial (IA) juega contra un jugador humano utilizando un algoritmo basado en el Minimax, que evalúa las jugadas posibles para elegir la mejor opción.

El algoritmo Minimax es un enfoque recursivo utilizado en juegos de dos jugadores, 
donde la IA trata de maximizar su puntuación mientras minimiza la puntuación del 
oponente. A continuación, se describen las funciones clave que implementan el 
algoritmo y el funcionamiento general del juego.

---
## Funciones Principales
    Tablero::chequearVictoria()
Esta función verifica si hay un ganador en el tablero. Recorre las filas, columnas y 
diagonales en busca de una secuencia de tres símbolos iguales (X u O). Si encuentra 
tal secuencia, devuelve el valor correspondiente al jugador ganador. 
Si no hay ganador y el tablero está lleno, devuelve un empate.

    IA::mejorMovimiento(Tablero& board, int jugador, int profundidad = 0);
    
La función getBestMove utiliza el algoritmo Minimax para calcular el mejor movimiento 
posible para la IA, recursivamente evaluando todas las jugadas posibles. 
La idea es que la IA optimiza su jugada eligiendo aquella que maximice su puntuación, 
mientras que minimiza la de su oponente.

El proceso de evaluación en el algoritmo Minimax se basa en tres posibles resultados:

1. Si la IA gana, se asigna un valor positivo.
2. Si el humano gana, se asigna un valor negativo.
3. Si hay un empate, se asigna un valor neutral.

### Algoritmo Minimax:
1. Si la IA gana, el valor es 10 - profundidad.
2. Si el humano gana, el valor es -10 + profundidad.
3. Si el tablero está lleno sin un ganador, se devuelve 0.
4. En cada turno, la IA evalúa todos los movimientos posibles, elige el que maximiza 
su puntuación y ejecuta ese movimiento.


    JuegoPrincipal::ejecutar()

El método principal del juego que gestiona el flujo de la partida, imprimiendo el 
tablero, realizando los movimientos de los jugadores y controlando el estado del 
juego (en curso, fin de juego, empate, etc.).

---

## Ejemplos Prácticos y Análisis de Casos Simples

### Caso 1: Movimiento Inicial
- El jugador X hace su primer movimiento en la casilla (1,1).
- La IA evalúa el estado del tablero y elige la siguiente mejor jugada, usando el 
algoritmo Minimax.

### Caso 2: Victoria del Jugador X
- Si el jugador X realiza una jugada en la casilla (2,2), y luego juega nuevamente 
en (3,3), logrará alinear tres símbolos en la diagonal.
- El algoritmo Minimax no necesitará explorar más movimientos porque ya se ha 
alcanzado una victoria.

### Caso 3: Empate
- Si todas las casillas están llenas sin que ninguno de los jugadores haya alineado 
tres símbolos, el juego terminará en empate.
- El algoritmo Minimax también detectará este caso y asignará una puntuación de 0.

---

## Explicación de la Búsqueda en el Árbol de Juego y su Evaluación
El árbol de juego se construye a medida que el juego avanza, con cada nodo 
representando un estado del tablero. Los nodos hijos representan los posibles 
movimientos de los jugadores. El algoritmo Minimax evalúa el árbol de la siguiente 
manera:

1. Nodo de la IA (Maximización): En los turnos de la IA, el algoritmo busca
maximizar su puntuación. Selecciona el movimiento que lleva al valor más alto
posible (es decir, el movimiento que le da la mayor oportunidad de ganar).
2. Nodo del Jugador (Minimización): En los turnos del jugador humano, 
el algoritmo busca minimizar la puntuación de la IA. Selecciona el 
movimiento que le da la menor oportunidad de ganar.

Cada movimiento en el árbol de juego tiene un puntaje asociado:

- +10 si la IA gana.
- -10 si el jugador humano gana.
- 0 si el resultado es empate.
El algoritmo realiza una búsqueda recursiva hasta que se alcanza una condición 
de victoria o empate, evaluando todas las opciones posibles para cada turno y
determinando la mejor jugada para la IA.

### Ejemplo de Búsqueda en el Árbol de Juego:
1. En el primer turno, el árbol tiene un solo nodo: el estado inicial del tablero.
2. La IA evalúa todos los movimientos posibles (nodos hijos) y asigna una puntuación 
a cada uno.
3. Para cada jugada, la IA también evalúa los movimientos del jugador humano (subnodos)
y les asigna puntuaciones.
4. Finalmente, la IA elige el movimiento con la puntuación más alta, asegurando su 
mejor opción a largo plazo.

---
## Conclusión
Este código permite simular un juego de Gato con un jugador humano y una IA basada 
en el algoritmo Minimax. La IA toma decisiones óptimas al evaluar todos los 
posibles movimientos y garantizar la victoria o minimizar la derrota. 
El código proporciona una buena base para la simulación de juegos y la 
implementación de algoritmos de búsqueda en árboles.
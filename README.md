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
## Explicación sobre el algoritmo utilizado (Minimax con poda alfa-beta)
En el código proporcionado, se implementa un algoritmo Minimax con poda alfa
-beta para tomar decisiones en un juego de gato, en el que una IA juega contra un 
humano. El algoritmo Minimax es utilizado para predecir los mejores movimientos, 
evaluando las posibles jugadas a lo largo del juego y eligiendo la más favorable 
para el jugador controlado por la IA.
### Proceso del algoritmo Minimax:
1. Objetivo: El objetivo principal del algoritmo es maximizar la puntuación de la 
IA mientras minimiza la puntuación del oponente (humano). Se considera que cada 
jugada tiene una "puntuación" que refleja su calidad, y el Minimax evalúa todos 
los posibles movimientos futuros para seleccionar el mejor.

2. Minimax: El algoritmo explora todos los posibles movimientos del tablero, 
creando un árbol de decisiones donde cada nodo representa un estado del tablero. 
Los nodos son evaluados y los movimientos son "maximizados" si le corresponde al 
jugador IA y "minimizados" si le corresponde al jugador humano.

3. Poda Alfa-Beta: La poda alfa-beta es una optimización del algoritmo Minimax 
que mejora su eficiencia. En lugar de explorar todos los posibles movimientos, 
alfa-beta permite descartar ramas del árbol de decisiones que no afectan al 
resultado final, ahorrando tiempo de cómputo.

   - Alfa es el valor máximo que el jugador IA puede obtener en cualquier 
   punto dado.
   - Beta es el valor mínimo que el jugador humano puede obtener.
   -Si en algún momento se detecta que un jugador no puede obtener un 
   resultado mejor que el valor de alfa o beta (es decir, que el nodo no puede 
   influir en la decisión final), esa rama del árbol de juego se "podará" 
   (no se explora más).

4. Recursividad: La función getBestMove es recursiva. En cada nivel del árbol de 
juego, se llama a sí misma con un estado del tablero actualizado, 
alternando entre maximizar y minimizar las puntuaciones dependiendo 
de si es el turno de la IA o el humano.

5. Evaluación: Cada posible movimiento se evalúa con una puntuación:

    - Si la IA gana, se devuelve un valor alto (10 menos la profundidad del nodo).
    - Si el humano gana, se devuelve un valor bajo (profundidad negativa -10).
    - Si el juego empata, el valor es 0.

La evaluación se realiza de manera recursiva para todos los 
posibles movimientos hasta alcanzar el final del juego (victoria, derrota o empate).

---
## Explicación teórica del algoritmo Minimax y la poda alfa-beta
### Algoritmo Minimax:
El algoritmo Minimax es una técnica utilizada en la toma de 
decisiones en teoría de juegos, especialmente en juegos de dos jugadores con 
información perfecta, como el ajedrez, las damas y el gato. 
El objetivo es que un jugador (en este caso, la IA) maximice su
puntuación mientras que el oponente (el jugador humano) trata de 
minimizar la puntuación de la IA.

- Maximización: Cuando es el turno de la IA, el algoritmo 
intenta maximizar la puntuación (es decir, encontrar el mejor movimiento para la IA).
- Minimización: Cuando es el turno del jugador humano, el 
algoritmo trata de minimizar la puntuación de la IA 
(es decir, encontrar el movimiento que le cause más daño a la IA).

### Poda Alfa-Beta:
La poda alfa-beta es una mejora del algoritmo Minimax que reduce el 
número de nodos evaluados al eliminar las ramas del árbol de juego 
que no pueden afectar el resultado final. Esto mejora la eficiencia 
del algoritmo de forma considerable.

- Alfa: Es el mejor valor encontrado hasta el momento en el lado 
"maximizador" del árbol (es decir, la IA). Si una rama encuentra un valor 
menor que alfa, no es necesario explorar más esa rama.
- Beta: Es el mejor valor encontrado hasta el momento en el lado "minimizador" 
del árbol (es decir, el jugador humano). Si una rama encuentra un valor mayor 
que beta, no es necesario explorar más esa rama.

La poda alfa-beta mantiene los mismos resultados que el algoritmo Minimax 
pero con una menor cantidad de nodos evaluados, lo que mejora el rendimiento de
manera significativa.

---
## Diagrama del árbol de juego para un caso simple

En este ejemplo, supongamos que la IA es el jugador X y el humano es el jugador O. El algoritmo evaluará las jugadas de la IA (maximizar) y las del humano (minimizar) en cada nivel del árbol.
### Estado actual:

     O | X | X
    -----------
     O |   |
    -----------
       | X | O

Supongamos que el juego ya está avanzado y la IA tiene 3 posibles jugadas con diferentes puntajes.

### Opción 1: Movimiento IA - X [2,2] 

     O | X | X
    -----------
     O | X |
    -----------
       | X | O
Luego de ejecutar el movimiento chequearemos el puntaje, si es una victoria (3 X en fila o columna) obtendremos 10 de puntaje (maximizar).

### Opción 2: Movimiento IA - X [2,2]


     O | X | X
    -----------
     O |   | X
    -----------
       | X | O

No se obtiene puntaje, ya que no se consigue nada, así que se vuelve a llamar recursivamente el algoritmo min-max, lo que simulalas jugadas del jugador "O", en donde tiene una victoria con cualquier movimiento, por lo cual se obtiene -10 al puntaje.

### Opción 3: Movimiento IA - X [1,3]

     O | X | X
    -----------
     O |   |
    -----------
     X | X | O

Volvemos a hacer la recursión, ya que no se obtiene puntaje, en donde es posible la victoria del jugador "O", por lo que el puntaje es -10.

### Árbol de juego:
                    [O|X|X] 
                    [O| | ]
                    [ |X|O]
                /      |       \
        [O][X][X]   [O][X][X]  [O][X][X]
        [O][X][ ]   [O][ ][X]  [O][ ][ ]
        [ ][X][O]   [ ][O][O]  [X][X][O]
                       / \             |    \
              [O][X][X] [O][X][X]  [O][X][X] [O][X][X]
              [O][ ][X] [O][O][X]  [O][O][ ] [O][ ][O]
              [O][X][O] [ ][X][O]  [ ][X][O] [ ][X][O]
                                                 |      \
                                             [O][X][X]  ...
                                             [O][X][O]
                                             [ ][X][O] 


---
## Análisis de complejidad temporal del algoritmo
### Antes de aplicar poda alfa-beta:
La complejidad temporal del algoritmo Minimax sin poda alfa-beta es O(b^d), donde:

- b es el factor de ramificación (el número promedio de movimientos posibles en
cada estado del juego).
- d es la profundidad del árbol de juego (el número de movimientos que se evalúan 
hacia adelante).
En el caso de un juego como el gato, si se consideraran todas las posibles 
jugadas, la complejidad sería mucho mayor, dado que el número de movimientos 
posibles crece exponencialmente con la profundidad.

### Después de aplicar poda alfa-beta:
La poda alfa-beta puede reducir la complejidad en gran medida, mejorando la 
eficiencia. En el mejor de los casos, la complejidad se reduce a O(b^(d/2)), 
lo que significa que la poda alfa-beta puede hacer que el algoritmo funcione mucho 
más rápido, evaluando significativamente menos nodos.

La mejora en la eficiencia depende en gran medida de cómo se ordenan las jugadas, 
ya que una mejor selección de movimientos puede llevar a podar más ramas, 
aumentando aún más la velocidad del algoritmo.

---
## Conclusión
Este código permite simular un juego de Gato con un jugador humano contra otro jugador o una IA basada 
en el algoritmo Minimax. La IA toma decisiones óptimas al evaluar todos los 
posibles movimientos y garantizar la victoria o minimizar la derrota, que en este caso resulta en un empate. 


---
## Instalación y Uso
- g++ src/main.cpp src/JuegoPrincipal.cpp src/IA.cpp src/Tablero.cpp -o main/main_executable


- ./main/main_executable

#pragma once

#include "IA.h"
#include "Tablero.h"

enum class GameState { PLAYING, EXIT };

class MainGame {
public:
    // Ejecuta el bucle principal del juego
    void ejecutar();

private:
    // Inicializa el juego
    void init();
    // Realiza un movimiento controlado por el jugador
    void movimientoJugador();
    // Realiza un movimiento de la IA
    void movimientoIA();
    // Cambia de jugador
    void cambiarJugador();
    // Termina el juego y pregunta si desea salir o volver a intentarlo
    void terminarJuego(bool empate);

    // Variables miembro
    Tablero _tablero; ///< El tablero de tic-tac-toe
    int _jugadorActual; ///< El índice del jugador actual
    int _aiPlayer; ///< El índice del jugador IA
    GameState _estadoDelJuego; ///< El estado del juego
    IA _IA; ///< El jugador IA
    bool _Multijugador;
};

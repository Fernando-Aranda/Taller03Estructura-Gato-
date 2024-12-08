#pragma once

#include "Tablero.h"

struct moverIA
{
	moverIA() {}
	moverIA(int Puntaje) : puntaje(Puntaje){}
	int x;
	int y;
	int puntaje;
};

class IA {
public:
    // Inicializa al jugador controlado por la IA
    void init(int playerIA);
    // Realiza el movimiento de la IA
    void accionMover(Tablero& board);
private:

	moverIA mejorMovimiento(Tablero& board, int jugador, int profundidad = 0);

    int _JugadorIA; ///< Índice de la IA
    int _JugadorHumano; ///< Índice del jugador humano
};

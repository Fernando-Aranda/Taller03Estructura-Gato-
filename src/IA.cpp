#include "../include/IA.h"

#include <vector>

void IA::init(int aiPlayer) {
    _JugadorIA = aiPlayer;
	_JugadorHumano = _JugadorIA == valorX ? valorO : valorX;
}

void IA::accionMover(Tablero& board) {
	moverIA bestMove = getBestMove(board, _JugadorIA);
	board.setVal(bestMove.x, bestMove.y, _JugadorIA);
}


moverIA IA::getBestMove(Tablero& board, int player, int depth /* = 0*/)
{
	int retv = board.chequearVictoria();

	if (retv == _JugadorIA) // si la IA ganó, retorna un valor alto
	{
		return moverIA(10 - depth);
	}
	else if (retv == _JugadorHumano) // si el humano ganó, retorna un valor bajo
	{
		return moverIA(depth - 10);
	}
	else if (retv == valorEmpate) // si nadie ganó, retorna 0
	{
		return moverIA(0);
	}

	depth++; // asegurarse de hacer siempre el movimiento más difícil para el humano

	std::vector<moverIA> moves;

	// recorrer los espacios vacíos
	for (int y = 0; y < board.getSize(); y++)
	{
		for (int x = 0; x < board.getSize(); x++)
		{
			if (board.getValor(x, y) == valorNo)
			{
				moverIA move;
				move.x = x;
				move.y = y;

				board.setVal(x, y, player);

				// verificar si es un buen movimiento
				move.puntaje = getBestMove(board, player == _JugadorIA ? _JugadorHumano : _JugadorIA, depth).puntaje;

				moves.push_back(move);

				board.setVal(x, y, valorNo);
			}
		}
	}

	// elegir el mejor movimiento
	int bestMove = 0;
	if (player == _JugadorIA)
	{
		int bestScore = -1000;
		for (size_t i = 0; i < moves.size(); i++)
		{
			if (moves[i].puntaje > bestScore)
			{
				bestMove = i;
				bestScore = moves[i].puntaje;
			}
		}
	}
	else
	{
		int bestScore = 1000;
		for (size_t i = 0; i < moves.size(); i++)
		{
			if (moves[i].puntaje < bestScore)
			{
				bestMove = i;
				bestScore = moves[i].puntaje;
			}
		}
	}

	// devolver el mejor movimiento
	return moves[bestMove];
}

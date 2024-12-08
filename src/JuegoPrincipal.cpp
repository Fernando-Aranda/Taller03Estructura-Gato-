#include "../include/JuegoPrincipal.h"
#include <iostream>

void MainGame::ejecutar() {
    init();
    // Bucle del juego
    while (_estadoDelJuego != GameState::EXIT) {
        // Imprimir el tablero
        _tablero.imprimir();
        // Anunciar qué jugador está jugando
        if (_jugadorActual == valorX) {
            printf("  Es el turno del Jugador X!\n\n");
        } else {
            printf("  Es el turno del Jugador O!\n\n");
        }
        // Realizar un movimiento
        if (!_Multijugador && _jugadorActual == _aiPlayer) {
            movimientoIA();
        } else {
            movimientoJugador();
        }
        // Verificar la condición de victoria
        int rv = _tablero.chequearVictoria();
        if (rv != valorNo) {
            terminarJuego(rv == valorEmpate);
        } else {
            cambiarJugador();
            // printf es más rápido que cout
            // Agregar un montón de espacio en blanco para "borrar" la consola
            for (int i = 0; i < 3; i++) {
                printf("\n");
            }
        }
    }
}

void MainGame::init() {
    _estadoDelJuego = GameState::PLAYING;
    _tablero.init(3);
    _jugadorActual = valorX;
   
    printf("\n\n---- Bienvenido al Gato ---- \n\n");

    // Verificar si es un juego multijugador
    printf("\n Quieres jugar Multijugador? (s/n):");
    char input = ' ';
    bool isValid;
    do {
        isValid = true;
        if (!(std::cin >> input)) {
            std::cout << "Entrada invalida!";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            isValid = false;
        } else if (input == 's' || input == 'S') {
            _Multijugador = true;
        } else {
            _Multijugador = false;
        }
    } while (isValid == false);
    
    if (!_Multijugador) {
        // Obtener jugador
        printf("\n Te gustaria ser X o O?");
        do {
            isValid = true;
            if (!(std::cin >> input)) {
                std::cout << "Entrada invalida!";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                isValid = false;
            } else if (input == 'x' || input == 'X') {
                _aiPlayer = valorO;
            } else if (input == 'o' || input == 'O') {
                _aiPlayer = valorX;
            } else {
                std::cout << "Debes ingresar X o O!";
                isValid = false;
            }
        } while (isValid == false);
        // Inicializar el jugador IA
        _IA.init(_aiPlayer);
    } 
    printf("\n\n");
}

void MainGame::movimientoJugador() {
    // Obtener entrada
    bool wasValid = false;

    int x, y;
    do {
        printf("Ingresa la X: ");
        while (!(std::cin >> x)) {
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            printf("ERROR: Entrada invalida!");
        }
        printf("Ingresa la Y: ");
        while (!(std::cin >> y)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            printf("ERROR: Entrada invalida!");
        }

        if (x < 1 || y < 1 || x > _tablero.getSize() || y > _tablero.getSize()) {
            printf("ERROR: X o Y invalidos!\n");
        } else if (_tablero.getValor(x - 1, y - 1) != 0) {
            printf("ERROR: Esa casilla esta ocupada!\n");
        } else {
            wasValid = true;
        }

    } while (!wasValid);

    // Colocar el token
    _tablero.setVal(x - 1, y - 1, _jugadorActual);
}

void MainGame::movimientoIA() {
    // TODO: Implementar esto
    _IA.accionMover(_tablero);
}

void MainGame::cambiarJugador() {
    if (_jugadorActual == valorX) {
        _jugadorActual = valorO;
    } else {
        _jugadorActual = valorX;
    }
}

void MainGame::terminarJuego(bool wasTie) {

    _tablero.imprimir();

    if (wasTie) {
        printf("\n\n Empate! Ingresa cualquier tecla para jugar de nuevo, o Z para salir: ");
    } else {
        if (_jugadorActual == valorX) {
            printf("\n\n  El Jugador X gana! Ingresa cualquier tecla para jugar de nuevo, o S para salir: ");
        } else {
            printf("\n\n  El Jugador O gana! Ingresa cualquier tecla para jugar de nuevo, o S para salir: ");
        }
    }

    char input;
    std::cin >> input;
    if (input == 'S' || input == 's') {
        _estadoDelJuego = GameState::EXIT;
    } else {
        // Re-iniciar el juego
        init();
    }
}

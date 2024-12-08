#include "../include/Tablero.h"
#include <string>

// Valores posibles de la casilla: ValorNo, ValorX, ValorO
const char Simbolos[3] = { ' ', 'X', 'O' };

void Tablero::init(int size) {
    // Limita el tamaño a 9 ya que tenemos espacio limitado en la consola
    if (size > 9) size = 9;
    _size = size;
    // Establece el tamaño del tablero
    _tablero.resize(size * size);
    // Lo limpia
    limpiar();
}

void Tablero::limpiar() {
    for (size_t i = 0; i < _tablero.size(); i++) {
        _tablero[i] = valorNo;
    }
}

void Tablero::imprimir() const {
    // En lugar de llamar a printf varias veces, construimos una única
    // cadena y llamamos a printf una vez, ya que es más rápido.

    std::string text = "";
    // Solo reservamos suficiente memoria, esto debería ser suficiente
    text.reserve(_size * _size * 4);

    // Crear la guía superior
    addLineaGuia(text);

    // Recorrer las filas
    for (int y = 0; y < _size; y++) {
        // Agregar línea horizontal para cada fila
        addLineaHorizontal(text);

        // Imprimir el número de la fila al inicio de la fila
        text += std::to_string(y + 1) + "|";

        // Recorrer las columnas y agregar el glifo (X o O)
        for (int x = 0; x < _size; x++) {
            text += " " + std::string(1, Simbolos[getValor(x, y)]) + " ";
            text += "|";
        }

        text += "\n";
    }

    // Agregar línea inferior (sin guía al final)
    addLineaHorizontal(text);

    // printf es más rápido que cout
    
    // Imprimir la cadena
    printf("%s\n", text.c_str());
}

int Tablero::chequearVictoria() const {
    bool victory;
    int c;
    // Comprobar las filas
    for (int y = 0; y < _size; y++) {
        c = getValor(0, y);
        if (c != valorNo) {
            victory = true;
            for (int x = 0; x < _size; x++) {
                if (getValor(x, y) != c) {
                    victory = false;
                    break;
                }
            }
            if (victory) return c;
        }
    }

    // Comprobar las columnas
    for (int x = 0; x < _size; x++) {
        c = getValor(x, 0);
        if (c != valorNo) {
            victory = true;
            for (int y = 0; y < _size; y++) {
                if (getValor(x, y) != c) {
                    victory = false;
                    break;
                }
            }
            if (victory) return c;
        }
    }

    // Comprobar la diagonal superior izquierda
    c = getValor(0, 0);
    if (c != valorNo) {
        victory = true;
        for (int xy = 0; xy < _size; xy++) {
            if (getValor(xy, xy) != c) {
                victory = false;
                break;
            }
        }
        if (victory) return c;
    }

    // Comprobar la diagonal superior derecha
    c = getValor(_size - 1, 0);
    if (c != valorNo) {
        victory = true;
        for (int xy = 0; xy < _size; xy++) {
            if (getValor(_size - xy - 1, xy) != c) {
                victory = false;
                break;
            }
        }
        if (victory) return c;
    }

    // Comprobar si hay empate
    for (size_t i = 0; i < _tablero.size(); i++) {
        if (_tablero[i] == valorNo) return valorNo;
    }
    // Si llegamos aquí, todas las casillas fueron llenadas, por lo que hay empate
    return valorEmpate;
}

void Tablero::addLineaHorizontal(std::string& s) const {
    s += "-";
    for (int x = 0; x < _size; x++) {
        s += "---";
    }
    s += "-\n";
}

void Tablero::addLineaGuia(std::string& s) const {
    s += " ";
    for (int i = 1; i <= _size; i++) {
        s += "| " + std::to_string(i) + " ";
    }
    s += "|\n";
}

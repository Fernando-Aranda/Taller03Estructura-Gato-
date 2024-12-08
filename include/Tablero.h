#pragma once

#include <vector>
#include <string>

const int valorEmpate = -1;
// Índices para los valores del tablero
const int valorNo = 0;
const int valorX = 1;
const int valorO = 2;

// NOTA: El const después de un nombre de función hace que la función sea constante,
// indicando que la función no cambiará nada en la clase.
// Las funciones constantes NO PUEDEN llamar a funciones no constantes de la misma clase.

// Clase para el tablero de juego
class Tablero {
public:
   
    // Inicializa el tablero
    void init(int size);
    // Limpia el tablero
    void limpiar();
    // Imprime el tablero en la salida estándar
    void imprimir() const;

    // Si ningún jugador ha ganado, devuelve valorNo. Si no, devuelve valorX, valorO o valorEmpate
    int chequearVictoria() const;

    // Establece el valor en la posición x,y
    void setVal(int x, int y, int val) {
        _tablero[y * _size + x] = val;
    }

    // Obtiene el valor en la posición x,y
    int getValor(int x, int y) const {
        return _tablero[y * _size + x];
    }

    // Métodos getter
    int getSize() const { return _size; }

private:
    // Agrega una línea horizontal a la cadena para imprimir
    void addLineaHorizontal(std::string& s) const;
    // Agrega una línea guía del eje horizontal a la cadena para imprimir
    void addLineaGuia(std::string& s) const;

    std::vector<int> _tablero;
    int _size;
};

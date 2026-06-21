#include <iostream>
#include <vector>
#include "letras.h"

using namespace std;

int main() {
    // 1. Declaramos un vector<char> con una frase de "La Marcha de las Letras".
    vector<char> letras = {'L', 'A', 'M', 'A', 'R', 'C', 'H', 'A'};

    // 2. Impresion tradicional: orden original usando un for y .size().
    cout << "Original:";
    for (size_t i = 0; i < letras.size(); i++) {
        cout << " " << letras[i];
    }
    cout << endl;// Este salto de línea cierra la fila "Original''

    // 3. Impresion en orden inverso usando indices (del ultimo al primero).
    cout << "Inverso:";
    for (size_t i = letras.size(); i > 0; i--) {
        cout << " " << letras[i - 1];
    }
    cout << endl; // Este salto de línea cierra la fila "Inverso"

    // 4 y 5. Contamos las vocales del vector y mostramos el resultado.
    cout << "Numero de vocales: " << contarVocales(letras) << endl;

    // Guardamos una copia del vector base (8 letras) para usarla mas adelante
    // en la parte de la matriz (2D), antes de extender el vector.
    vector<char> base = letras;

    // 9. Usamos .push_back() para agregar el resto de la frase: "DE LAS LETRAS".
    vector<char> resto = {'D', 'E', 'L', 'A', 'S', 'L', 'E', 'T', 'R', 'A', 'S'};
    for (char c : resto) {
        letras.push_back(c);
    }

    // 10. Imprimimos el vector extendido completo (range-based for loop).
    cout << "Vector extendido:";
    for (char c : letras) {
        cout << " " << c;
    }
    cout << endl;

    // 11. Volvemos a contar las vocales, ahora con el vector completo.
    cout << "Numero de vocales en el vector extendido: " << contarVocales(letras) << endl;

    // Fila 0: el vector base original.
    // Fila 1: el vector base rotado una posicion a la derecha
    //         (el ultimo caracter pasa al frente).
    vector<vector<char>> matriz;
    matriz.push_back(base);

    vector<char> fila_rotada;
    fila_rotada.push_back(base.back());              // el ultimo elemento va primero
    for (size_t i = 0; i + 1 < base.size(); i++) {   // luego el resto en orden
        fila_rotada.push_back(base[i]);
    }
    matriz.push_back(fila_rotada);

    // Imprimimos cada fila de la matriz.
    for (size_t f = 0; f < matriz.size(); f++) {
        cout << "Fila " << f << ":";
        for (char c : matriz[f]) {
            cout << " " << c;
        }
        cout << endl;
    }

    // Contamos las vocales de ambas filas combinadas.
    int vocalesCombinadas = 0;
    for (size_t f = 0; f < matriz.size(); f++) {
        vocalesCombinadas += contarVocales(matriz[f]);
    }
    cout << "Numero de vocales en ambas filas combinadas: " << vocalesCombinadas << endl;

    return 0;
}

// Ejercicio: Ejercicio 07 - Cifrado César
// Autor: [Tu Nombre Aquí]
// Revisor: [Nombre de tu Compañero Aquí]

#include <iostream>
#include <string>

using namespace std;

int main() {
    string texto, resultado = "";
    int desplazamiento, opcion;

    cout << "--- CIFRADO CÉSAR ---" << endl;
    cout << "1. Cifrar texto" << endl;
    cout << "2. Descifrar texto" << endl;
    cout << "Seleccione una opción (1-2): ";
    cin >> opcion;
    cin.ignore(); 

    if (opcion != 1 && opcion != 2) {
        cout << "Opción no válida. Saliendo del programa." << endl;
        return 1;
    }

    cout << "Ingrese el texto: ";
    getline(cin, texto);

    cout << "Ingrese el desplazamiento (1-25): ";
    cin >> desplazamiento;

    if (desplazamiento < 1 || desplazamiento > 25) {
        cout << "Desplazamiento inválido. Debe estar entre 1 y 25." << endl;
        return 1;
    }

    if (opcion == 2) {
        desplazamiento = 26 - desplazamiento;
    }

    for (char c : texto) {
        if (c >= 'A' && c <= 'Z') {
            char nuevo = (c - 'A' + desplazamiento) % 26 + 'A';
            resultado += nuevo;
        } else if (c >= 'a' && c <= 'z') {
            char nuevo = (c - 'a' + desplazamiento) % 26 + 'a';
            resultado += nuevo;
        } else {
            resultado += c;
        }
    }

    if (opcion == 1) {
        cout << "\nTexto cifrado: " << resultado << endl;
    } else {
        cout << "\nTexto descifrado: " << resultado << endl;
    }

    return 0;
}

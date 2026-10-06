// Ejercicio: Ejercicio 08 - Análisis de un número
// Autor: [Tu Nombre]
// Revisor: [Nombre Compañero]

#include <iostream>
#include <cmath>

using namespace std;

int sumarDigitos(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int invertirNumero(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = (invertido * 10) + (n % 10);
        n /= 10;
    }
    return invertido;
}

bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool esArmstrong(int n) {
    int original = n;
    int suma = 0;
    int digitos = 0;
    int temp = n;
    while (temp > 0) {
        digitos++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0) {
        int digito = temp % 10;
        suma += round(pow(digito, digitos));
        temp /= 10;
    }
    return (suma == original);
}

int main() {
    int numero, opcion;
    cout << "--- ANÁLISIS DE UN NÚMERO ---" << endl;
    cout << "Ingrese un entero positivo para analizar: ";
    cin >> numero;
    if (numero <= 0) {
        cout << "Error: El número debe ser un entero positivo." << endl;
        return 1;
    }
    do {
        cout << "\n===============================" << endl;
        cout << "MENU DE OPCIONES (Número: " << numero << ")" << endl;
        cout << "1. Sumar sus dígitos" << endl;
        cout << "2. Invertir el número" << endl;
        cout << "3. Decir si es primo" << endl;
        cout << "4. Decir si es número de Armstrong" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción (1-5): ";
        cin >> opcion;
        cout << "===============================" << endl;
        switch (opcion) {
            case 1: cout << "Suma de dígitos: " << sumarDigitos(numero) << endl; break;
            case 2: cout << "Invertir: " << invertirNumero(numero) << endl; break;
            case 3: cout << "Primo: " << (esPrimo(numero) ? "sí" : "no") << endl; break;
            case 4: cout << "Armstrong: " << (esArmstrong(numero) ? "sí" : "no") << endl; break;
            case 5: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 5);
    return 0;
}



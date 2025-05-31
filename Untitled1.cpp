#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void LimpiarPantalla();
void JugarPartida();
void Dibujar();

char eleccion;
string palabras[] = {"monitor","microfono","televisor","telefono","caja","fibron","teclado","pc","collar","manzana"};
string palabra, fallidas;
int nA;
int vida;
bool correcta;

int main() {
    while (true) {
        vida = 6;
        palabra = "";
        fallidas = "";
        LimpiarPantalla();
        cout << "\t::::MENU::::" << endl;
        cout << "1) Jugar Partida." << endl;
        cout << "2) Salir." << endl;
        cout << "Eleccion: ";
        cin >> eleccion;
        switch (eleccion) {
            case '1':
                JugarPartida();
                break;
            case '2':
                return 0;
            default:
                cout << "Opcion invalida. Presiona una tecla para continuar." << endl;
                cin.ignore();
                cin.get();
                break;
        }
    }
}

void JugarPartida() {
    srand((int)time(NULL));
    nA = rand() % 10;

    palabra = string(palabras[nA].size(), '-');

    while (vida > 0) {
        LimpiarPantalla();
        cout << "\t::: A H O R C A D O :::" << endl;
        Dibujar();
        cout << "Fallos: " << fallidas << "  Progreso: " << palabra << endl;
        cout << "Ingrese una letra (minúscula): ";
        cin >> eleccion;

        // Validar que sea letra minúscula
        if (!islower(eleccion) || !isalpha(eleccion)) {
            cout << "Entrada inválida. Presiona una tecla para continuar.";
            cin.ignore();
            cin.get();
            continue;
        }

        // Verificar si ya se intentó
        if (fallidas.find(eleccion) != string::npos || palabra.find(eleccion) != string::npos) {
            cout << "Ya intentaste con esa letra. Presiona una tecla para continuar.";
            cin.ignore();
            cin.get();
            continue;
        }

        correcta = false;
        for (int i = 0; i < (int)palabras[nA].size(); i++) {
            if (palabras[nA][i] == eleccion) {
                palabra[i] = eleccion;
                correcta = true;
            }
        }

        if (!correcta) {
            vida--;
            fallidas += eleccion;
        }

        if (palabra.find('-') == string::npos) {
            LimpiarPantalla();
            cout << "\t::: A H O R C A D O :::" << endl;
            Dibujar();
            cout << "Palabra: " << palabras[nA] << endl;
            cout << "¡Ganaste! Presiona una tecla para continuar.";
            cin.ignore();
            cin.get();
            return;
        }
    }

    LimpiarPantalla();
    cout << "\t::: A H O R C A D O :::" << endl;
    Dibujar();
    cout << "Palabra: " << palabras[nA] << endl;
    cout << "Perdiste. Presiona una tecla para continuar.";
    cin.ignore();
    cin.get();
}

void Dibujar() {
    switch (vida) {
        case 6:
            cout<<"  --------\n  |      |\n  |\n  |\n  |\n  |\n  |\n ---\n";
            break;
        case 5:
            cout<<"  --------\n  |      |\n  |      O\n  |\n  |\n  |\n  |\n ---\n";
            break;
        case 4:
            cout<<"  --------\n  |      |\n  |      O\n  |      |\n  |\n  |\n  |\n ---\n";
            break;
        case 3:
            cout<<"  --------\n  |      |\n  |      O\n  |     /|\n  |\n  |\n  |\n ---\n";
            break;
        case 2:
            cout<<"  --------\n  |      |\n  |      O\n  |     /|\\\n  |\n  |\n  |\n ---\n";
            break;
        case 1:
            cout<<"  --------\n  |      |\n  |      O\n  |     /|\\\n  |     /\n  |\n  |\n ---\n";
            break;
        case 0:
            cout<<"  --------\n  |      |\n  |      O\n  |     /|\\\n  |     / \\\n  |\n  |\n ---\n";
            break;
    }
}

void LimpiarPantalla() {
    // Alternativa multiplataforma simple a system("clear")
    for (int i = 0; i < 50; i++) cout << endl;
}

// =========================================================
// Nombre: main.cpp
// Autor: Axel Camacho Villafuerte.
// Fecha: 14/09/2023.
// Versión: 2.0.4.
// Descripción: Un invernadero.
// =========================================================

#include <iostream>
#include <vector>
#include <fstream>
//#include <algorithm>

#include "Invernadero.h"

using namespace std;

int main() {
    //Crear un objeto de la clase Invernadero
    Invernadero invernadero;
    
    //sort(invernadero.getInvernadero().begin(), invernadero.getInvernadero().end());

    //Inicialización de variables
    string flor; //Nombre de la flor
    int floresAnadir; //Número de flores a ingresar
    string florAbuscar; //String a buscar en la lista
    int index; //Indice de la lista

    //Abrir el archivo
    ifstream inputfile("flores.txt");
    string linea;

    //Verificar si el archivo se abrió correctamente
    if (!inputfile.is_open()) {
        cout << "main.cpp" << ": File \"" << "flores.txt" << "\" not found\n";
        return -1;
    }

    //Variable para guardar la opción
    int opcion = 0;

    //Ciclar menú
    while (opcion != 6) {
        //Menú
        cout << "¿Qué harás hoy en tu invernadero?\n"
            << "1.- Imprimir el invernadero\n" 
            << "2.- Añadir flores al invernadero\n"
            << "3.- Ordenar flores\n" 
            << "4.- Busqueda binaria de flores\n"
            << "5.- Llenar invernadero con un archivo.txt\n"
            << "6.- Finalizar" << endl;

        //Solicitar al usuario que ingrese un valor
        cout << "Ingrese una opción (1, 2, 3, 4, 5 o 6): ";
        cin >> opcion;

        //Limpia la terminal de windows
        system("cls");

        //Switch para opcciones
        switch (opcion) {
            case 1:
                //Imprimir el invernadero
                invernadero.imprimirInvernadero();
                break;

            case 2:
                //Ingresar número de flores a añadir
                cout << "Número de flores a añadir: ";
                cin >> floresAnadir;
                //Añadir flores al invernadero
                //Ciclo
                for (int i = 0; i < floresAnadir; i++) {
                    cout << "Flores a añadir: " << endl;
                    cin >> flor;
                    invernadero.agregarFlor(flor);
                }
                break;

            case 3:
                //Ordenar el invernadero
                invernadero.ordenaSeleccion(invernadero.getInvernadero());
                break;

            case 4:
                //Condicional que verifica si existe el arreglo
                //.empty() devolver True o False si un vector esta lleno o vacío
                if (invernadero.getInvernadero().empty()) {
                    cout << "No hay flores en el invernadero." << endl;
                    break;
                }

                //Ordenar el invernadero
                invernadero.ordenaSeleccion(invernadero.getInvernadero());
                
                //Flor a buscar
                cout << "Flor a buscar: " << endl;
                cin >> florAbuscar;

                //Ciclo for para convertir a minusculas
                for (char &c : florAbuscar) {
                    c = tolower(c);
                }

                //Guardar indice de la lista
                index = invernadero.busqBinaria(invernadero.getInvernadero(), florAbuscar);
                //Condicional para imprimir si existe, si no imprimir el indice
                if (index == -1) cout << "Flor no encontrada" << endl;
                else cout << index << endl;
                break;

            case 5:
                //Verifica si el archivo está cerrado
                if (!inputfile.is_open()) {
                    cout << "El archivo está cerrado." << endl;
                    break;
                }
                //Leer cada línea del archivo y agregarla al vector
                while (getline(inputfile, linea)) {
                    invernadero.agregarFlor(linea);
                }

                //Cerrar el archivo después de leer
                inputfile.close();
                break;

            case 6:
                //Terminar programa
                cout << "Finalizando" << endl;
                break;
                
            default:
                //Si no se selecciono una opcción
                cout << "Opción no válida." << endl;
                break;
        }
    }

    return 0;
}

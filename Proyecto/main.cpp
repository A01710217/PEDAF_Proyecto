// =========================================================
// Nombre: main.cpp
// Autor: Axel Camacho Villafuerte.
// Fecha: 14/09/2023.
// Versión: 2.0.0.
// Descripción: Un invernadero.
// =========================================================

#include <iostream>
#include <vector>
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
    string valor; //String a buscar en la lista
    int index; //Indice de la lista

    //Variable para guardar la opción
    int opcion = 0;

    //Ciclar menú
    while (opcion != 5) {    
        //Menú
        cout << "¿Qué haras hoy en tu invernadero?\n"
            << "1.- Imprimir el invernadero\n" 
            << "2.- Añadir flores al invernadero\n"
            << "3.- Ordenar flores\n" 
            << "4.- Busqueda binaria\n"
            << "5.- Salir" << endl;

        //Solicitar al usuario que ingrese un valor
        cout << "Ingrese una opción (1, 2, 3, 4 o 5): ";
        cin >> opcion;

        //Switch
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
                cin >> valor;

                //Guardar indice de la lista
                index = invernadero.busqBinaria(invernadero.getInvernadero(), valor);
                //Condicional para imprimir si existe, si no imprimir el indice
                if (index == -1) cout << "Flor no encontrada" << endl;
                else cout << index << endl;
                break;

            case 5:
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

// =========================================================
// Nombre: main.cpp
// Autor: Axel Camacho Villafuerte.
// Fecha: 12/11/2023.
// Versión: 3.2.0.
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
    Invernadero<string> invernadero;
    
    //sort(invernadero.getInvernadero().begin(), invernadero.getInvernadero().end());

    //Inicialización de variables
    string flor; //Nombre de la flor
    int floresAnadir; //Número de flores a ingresar
    string florAbuscar; //String a buscar en la lista
    int index; //Indice de la lista

    //Abrir el archivo
    ifstream inputfile("flores.txt");
    ofstream outputFile("output.txt");
    string linea;

    //Abrir los archivos
    //inputfile.open("flores.txt");
    //outputFile.open("output.txt");

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
        cout << "Que haras hoy en tu invernadero?\n"
            << "1.- Imprimir el invernadero\n" 
            << "2.- Anadir flores al invernadero\n"
            << "3.- Ordenar flores de la A a la Z\n" 
            << "4.- Buscar una flor\n"
            << "5.- Llenar invernadero con un archivo.txt\n"
            << "6.- Finalizar" << endl;

        //Solicitar al usuario que ingrese un valor
        cout << "Ingrese una opcion (1, 2, 3, 4, 5 o 6): ";
        cin >> opcion;

        //Limpia la terminal de windows
        system("cls");

        //Switch para opcciones
        switch (opcion) {
            case 1:
                if (invernadero.empty() == true) {
                    cout << "No hay flores en el invernadero." << endl;
                    break;
                }
                //Imprimir el invernadero
                cout << invernadero.imprimirInvernadero() << endl;
                break;

            case 2:
                //Ingresar número de flores a añadir
                cout << "Numero de flores a anadir: ";
                cin >> floresAnadir;
                //Añadir flores al invernadero
                //Ciclo
                for (int i = 0; i < floresAnadir; i++) {
                    cout << "Flores a anadir: " << endl;
                    cin >> flor;
                    invernadero.agregarFlor(flor);
                }
                break;

            case 3:
                //Condicional que verifica si existe una flor en el invernadero
                if (invernadero.empty() == true) {
                    cout << "No hay flores en el invernadero." << endl;
                    break;
                }
                //Ordenar el invernadero
                invernadero.quicksort();
                break;

            case 4:
                //Condicional que verifica si existe una flor en el invernadero
                if (invernadero.empty() == true) {
                    cout << "No hay flores en el invernadero." << endl;
                    break;
                }

                //Ordenar el invernadero
                invernadero.quicksort();
                
                //Flor a buscar
                cout << "Flor a buscar: " << endl;
                cin >> florAbuscar;

                //Ciclo for para convertir a minusculas
                for (char &c : florAbuscar) {
                    c = tolower(c);
                }

                //Guardar indice de la lista
                invernadero.search(florAbuscar);
                //Condicional para imprimir si existe, si no imprimir el indice
                if (invernadero.search(florAbuscar) == -1) cout << "Flor no encontrada" << endl;
                else cout << invernadero.search(florAbuscar) << endl;
                break;

            case 5:
                //Verifica si el archivo está cerrado
                if (!inputfile.is_open()) {
                    cout << "El archivo está cerrado." << endl;
                    break;
                }

                cout << "Llenando invernadero..." << endl;

                //Leer cada línea del archivo y agregarla al vector
                while (getline(inputfile, linea)) {
                    invernadero.agregarFlor(linea);
                }

                //Cerrar el archivo después de leer
                inputfile.close();
                break;

            case 6:
                //Terminar programa
                cout << "Generando archivo..." << endl;
                //Imprimir el invernadero
                outputFile << invernadero.imprimirInvernaderoArchivo();
                //Cerrar el archivo después de escribir
                outputFile.close();

                //Limpiar la lista
                invernadero.clear();

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

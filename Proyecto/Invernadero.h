// =========================================================
// Nombre: Invernadero.h
// Autor: Axel Camacho Villafuerte.
// Fecha: 14/09/2023.
// //Descripción: Creacción de un invernadero
// =========================================================

#ifndef INVERNADERO_H
#define INVERNADERO_H

#include <iostream>
#include <vector>

class Invernadero {
    private:
        //Variables
        std::vector<std::string> invernadero; //Definir nuestro vector
        //Metodos de ayuda para organizar valores
        void intercambiarFlores(std::vector<std::string> &, int, int); //Metodo visto en clase, intercambia valores de los indices
        //Metodo auxiliar para busqueda recurisva
        int bs_aux(std::vector<std::string> &, int, int, std::string val);
    public:
        //Metodos
        std::vector<std::string>& getInvernadero(); //Obtener el vector
        void agregarFlor(std::string &flor); //Agrega determinada cantidad de flores al vector
        void imprimirInvernadero(); //Imprime el vector
        void ordenaSeleccion(std::vector<std::string> &); //Metodo de ordenamiento
        int busqBinaria(const std::vector<std::string> &, const std::string &); //Metodo de busqueda binaria
};

void Invernadero::intercambiarFlores(std::vector<std::string> &v, int i, int j) {
	std::string aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

std::vector<std::string>& Invernadero::getInvernadero() {
    return invernadero;
}

void Invernadero::agregarFlor(std::string &flor) {
    //Ciclo for para convertir a minusculas
    for (char &c : flor) {
        c = tolower(c);
    }
    invernadero.push_back(flor);
}

void Invernadero::imprimirInvernadero() {
    if (invernadero.empty()) std::cout << "No hay flores en el invernadero." << std::endl;
    else {
        std::cout << "Flores en el invernadero:" << std::endl;
        for (int i = 0; i < invernadero.size() - 1; i++) {
            std::cout << invernadero[i] << std::endl;
        }
    }
}

void Invernadero::ordenaSeleccion(std::vector<std::string> &invernadero) {
    if (invernadero.empty()) std::cout << "No hay flores que ordenar en el invernadero." << std::endl;
    else {
        int posicion;

        for (int i = invernadero.size() - 1; i > 0; i--) {
            posicion = 0;
            for (int j = 1; j <= i; j++) {
                if (invernadero[j] > invernadero[posicion]) {
                    posicion = j;
                }
            }

            if (posicion != i) {
                intercambiarFlores(invernadero, i, posicion);
            }
        }
    }

}

int Invernadero::bs_aux(std::vector<std::string> &invernadero, int low, int high, std::string val) {
    //Inicializar variable mid
    int mid;
 
    //Condicion de paro
    if (low <= high) {
        mid = (high + low) / 2; //Obtener medio
        int compare_result = val.compare(invernadero[mid]); //Comparar el valor con el valor del indece mid
        //Condicional para hacer recursión
        if (compare_result == 0)
            return mid; //Regresar indice del valor
        else if (compare_result < 0)
            return bs_aux(invernadero, low, mid - 1, val); //Recursión, busqueda binaria en el extremo inferior
        else
            return bs_aux(invernadero, mid + 1, high, val); //Recursión, busqueda binaria en el extremo superior
    }
    return -1;  //Flor no encontrada.
}

int Invernadero::busqBinaria(const std::vector<std::string> &invernadero, const std::string &val) {
    std::vector<std::string> copia_invernadero = invernadero; //Hacer una copia del invernadero
    //Retornar indice
    return bs_aux(copia_invernadero, 0, invernadero.size() - 1, val);
}

#endif

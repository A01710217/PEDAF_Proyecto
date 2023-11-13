// =========================================================
// Nombre: Invernadero.h
// Autor: Axel Camacho Villafuerte.
// Fecha: 15/10/2023.
// //Descripción: Creacción de un invernadero
// =========================================================

#ifndef INVERNADERO_H
#define INVERNADERO_H

#include <iostream>
#include <string>
#include <sstream>

template <class T> class Invernadero; //Adelantar declaracion de clase invernadero

template <class T>
class Link {
	private:
		//Variables
    	std::string value;
    	Link<T>* next;

		//Constructores
		Link(T);
		//Definir clase Link como amiga de la clase Invernadero
		friend class Invernadero<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(nullptr) {}

template <class T>
class Invernadero {
	private:
		//Variables
		Link<T> *headFlores;

    public:
		//Constructor
		Invernadero();
		//Destructor
        ~Invernadero();
		//Metodos
        bool empty() const; //Metodo empty() para saber si la lista está vacía
        void clear(); //Metodo clear() para borrar la lista

		void agregarFlor(T); //Metodo agregarFlor() para insertar un elemento
		int search(T); //Devuelve el indice del elemento buscado
    	void update(int, T); //Metodo update() para actualizar un elemento
    	void deleteAt(int); //Metodo deleteAt() para borrar un elemento
        void seleccionSort(); //Metodo selectionSort() para ordenar la lista

        int getTamno(); //Metodo getTamno() para obtener el tamaño de la lista
		
        T imprimirInvernaderoArchivo() const; //Metodo toString() para convertir la lista en string
		T imprimirInvernadero() const; //Metodo toString() para convertir la lista en string
};

template <class T>
Invernadero<T>::Invernadero() : headFlores(nullptr) {}

template <class T>
Invernadero<T>::~Invernadero() {
	clear();
}

//Metodo clear() visto en clase
template <class T>
void Invernadero<T>::clear() {
	//Creamos dos punteros auxiliares
	Link<T> *p, *q;

	//Inicializamos p con el valor de headFlores
	p = headFlores;
	//Ciloc while para recorrer la lista y borrar los nodos
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	//Asignamos el valor de headFlores a nullptr
	headFlores = 0;
}

template <class T>
bool Invernadero<T>::empty() const {
	return (headFlores == 0);
}

template <class T>
void Invernadero<T>::agregarFlor(T flor) {

    int index = search(flor);
    //If para verificar si la flor ya existe
    if (index != -1) {
        std::cout << "La flor ya existe." << "El indice es: " << index << std::endl;
        return;
    }

    //Ciclo para convertir a minusculas
    for (char &c : flor) {
        c = tolower(c);
    }

	//Creamos un nuevo nodo
    Link<T>* newVal = new Link<T>(flor);

    if (headFlores == 0) {
        headFlores = newVal;
    } else {
        Link<T>* current = headFlores;
        while (current->next != 0) {
            current = current->next;
        }
        current->next = newVal;
    }
}

template <class T>
int Invernadero<T>::search(T flor) {
    //Ciclo para convertir a minusculas
    for (char &c : flor) {
        c = tolower(c);
    }

	Link<T> *current = headFlores;
	int index = 0;
	while (current) {
		if (current->value == flor) {
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}

template <class T>
void Invernadero<T>::update(int index, T flor) {
    //Ciclo para convertir a minusculas
    for (char &c : flor) {
        c = tolower(c);
    }

    //Creamos un puntero auxiliar para recorrer la lista
    Link<T> *current = headFlores;

    //Mediante un cilco for, recorremos hasta llegar al índice deseado
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    //Actualizamos el valor en el índice dado
    current->value = flor;
}

template <class T>
void Invernadero<T>::deleteAt(int index) {
    if (index == 0) {
        Link<T> *temp = headFlores;
        headFlores = headFlores->next;
        delete temp;
    } else {
        Link<T> *current = headFlores;
        int currentIndex = 0;
        while (current) {
            if (currentIndex == index - 1) {
                Link<T> *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            current = current->next;
            currentIndex++;
        }
    }
}

template <class T>
void Invernadero<T>::seleccionSort() {
    Link<T> *p, *q, *min;
    p = headFlores;
    
    while (p != nullptr) {
        min = p;
        q = p->next;

        while (q != nullptr) {
            if (q->value < min->value) {
                min = q;
            }
            q = q->next;
        }

        if (min != p) {
            std::string temp = p->value;
            p->value = min->value;
            min->value = temp;
        }

        p = p->next;
    }
}

template <class T>
int Invernadero<T>::getTamno() {
    //Creamos un puntero auxiliar para recorrer la lista
    Link<T> *current = headFlores;

    //Creamos una variable para contar el tamaño de la lista
    int tamano = 0;

    //Mediante un cilco for, recorremos hasta llegar al índice deseado
    while (current != nullptr) {
        current = current->next;
        tamano++;
    }

    return tamano;
}

template <class T>
T Invernadero<T>::imprimirInvernaderoArchivo() const {
	std::stringstream aux;
	Link<T> *p;

	p = headFlores;
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << std::endl;
		}
		p = p->next;
	}
	return aux.str();
}

template <class T>
T Invernadero<T>::imprimirInvernadero() const {
    std::stringstream aux;
    Link<T> *p;

    aux << "[";	
    p = headFlores;
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "[";	

    return aux.str();
}

#endif

// =========================================================
// Nombre: Invernadero.h
// Autor: Axel Camacho Villafuerte.
// Fecha: 13/11/2023.
// Descripción: Creacción de un invernadero
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
    	T value;
    	Link<T>* next;
        Link<T>* prev; //Agregar este puntero

		//Constructores
		Link(T);
		//Definir clase Link como amiga de la clase Invernadero
		friend class Invernadero<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(nullptr), prev(nullptr) {}

template <class T>
class Invernadero {
	private:
		//Variables
		Link<T> *headFlores;
        void intercambiar(Link<T>* , Link<T>* ); //Metodo intercambiar() para intercambiar dos elementos

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
        Link<T>* partition(Link<T>*, Link<T>*); //Metodo partition() para ordenar la lista
        void quicksort_Aux(Link<T>*, Link<T>*); //Metodo quicksort_Aux() para ordenar la lista

        void quicksort(); //Metodo quicksort() para ordenar la lista

        int getTamno(); //Metodo getTamno() para obtener el tamaño de la lista
        Link<T>* getUltimo(); //Metodo getUltimo() para obtener el ultimo elemento de la lista
		
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
    Link<T>* newLink = new Link<T>(flor);

    newLink->next = headFlores;
    if (headFlores != nullptr) headFlores->prev = newLink;
    headFlores = newLink;
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
void Invernadero<T>::intercambiar(Link<T>* a, Link<T>* b) {
    T temp = a->value;
    a->value = b->value;
    b->value = temp;
}

template <class T>
Link<T>* Invernadero<T>::partition(Link<T>* low, Link<T>* high) {
    T pivot = high->value;
    Link<T>* i = low->prev;

    for (Link<T>* j = low; j != high; j = j->next) {
        if (j->value <= pivot) {
            i = (i == nullptr) ? low : i->next;
            intercambiar(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    intercambiar(i, high);
    return i;
}

template <class T>
void Invernadero<T>::quicksort_Aux(Link<T>* low, Link<T>* high) {
    if (high != nullptr && low != high && low != high->next) {
        Link<T>* p = partition(low, high);
        quicksort_Aux(low, p->prev);
        quicksort_Aux(p->next, high);
    }
}

template <class T>
void Invernadero<T>::quicksort() {
    quicksort_Aux(headFlores, getUltimo()); 
}

template <class T>
Link<T>* Invernadero<T>::getUltimo() {
    Link<T>* temp = headFlores;
    while (temp != nullptr && temp->next != nullptr) temp = temp->next;
    return temp;
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
    while (p) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";	

    return aux.str();
}

#endif

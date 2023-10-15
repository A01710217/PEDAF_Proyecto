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
		//Definir clase link como amiga de la clase List
		friend class Invernadero<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(nullptr) {}

template <class T>
class Invernadero {
	private:
		//Variables
		Link<T> *head;

    public:
		//Constructor
		Invernadero();
		//Destructor
        ~Invernadero();
		//Metodos
        bool empty() const; //Metodo empty() para saber si la lista está vacía
        void clear(); //Metodo clear() para borrar la lista

		void agregarFlor(T); //Metodo insertion() para insertar un elemento
		int search(T); //Devuelve el indice del elemento buscado
    	void update(int, T); //Metodo update() para actualizar un elemento
    	void deleteAt(int); //Metodo deleteAt() para borrar un elemento
        void seleccionSort(); //Metodo selectionSort() para ordenar la lista
		
		T imprimirInvernadero() const; //Metodo toString() para convertir la lista en string
};

template <class T>
Invernadero<T>::Invernadero() : head(nullptr) {}

template <class T>
Invernadero<T>::~Invernadero() {
	clear();
}

//Metodo clear() visto en clase
template <class T>
void Invernadero<T>::clear() {
	//Creamos dos punteros auxiliares
	Link<T> *p, *q;

	//Inicializamos p con el valor de head
	p = head;
	//Ciloc while para recorrer la lista y borrar los nodos
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	//Asignamos el valor de head a nullptr
	head = 0;
}

template <class T>
bool Invernadero<T>::empty() const {
	return (head == 0);
}

template <class T>
void Invernadero<T>::agregarFlor(T flor) {
    //Ciclo para convertir a minusculas
    for (char &c : flor) {
        c = tolower(c);
    }

	//Creamos un nuevo nodo
    Link<T>* newVal = new Link<T>(flor);

    if (head == 0) {
        head = newVal;
    } else {
        Link<T>* current = head;
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

	Link<T> *current = head;
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
    Link<T> *current = head;

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
        Link<T> *temp = head;
        head = head->next;
        delete temp;
    } else {
        Link<T> *current = head;
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
    p = head;
    
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
            // Swap the values of p and min
            std::string temp = p->value;
            p->value = min->value;
            min->value = temp;
        }

        p = p->next;
    }
}

template <class T>
T Invernadero<T>::imprimirInvernadero() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
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

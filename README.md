# Registro de invernadero.

### Este proyecto es un catálogo de nombres de flores (strings).

#### En el cual habarcare estos puntos:
- Un "cout" del registro del invernadero.
- Un metodo void agregarFlor(T), que añade nombres (strings) de flores.
- Un metodo de ordenamiento, por el metodo de "Quick sort".
- Un metodo de busqueda, el cual buscar flores en el invernadero.
- Un opcción que te permita llenar el arreglo con un archivo .txt.
- Un opccón para finalizar y genear un archivo .txt, lleno de lo que se realize en el main().

#### Proximamente:
- Modificación del readme

#### Análisis asintótica del archivo "Invernadero.h":
- T imprimirInvernadero() const; O(n)
- void agregarFlor(T); O(n)
- int search(T); O(n)
- void deleteAt(int); O(n)
- void quicksort(); O(nlog(n))

#### Se agrego un archivo test.cpp:
###### En el archivo se crearon casos, provando lafuncionalidad de los metodos mas importantes:
- void agregarFlor(T); 
- int search(T); 
- void update(int, T); 
- void deleteAt(int); 
- void quicksort();
- void clear();


## SICT0302B: Toma decisiones.

### Selecciona y usa una estructura adecuada al problema.

##### Usé una "Linked list", devido a que la cantidad de datos son 130. Para esta cantidad nesesitaba una estructura donde la inserciónn y la eliminación son sensillas y eficientes. También me son de utilidad devido a que la asignación de memoria dinámica y puedo agregar tantoas datos como lo nesesite el registro. 

### Selecciona un algoritmo de ordenamiento adecuado al problema.

#### Usé el algoritmo de ordenamiento Quick sort, este algoritmo organiza nombres de flores de la A a la Z. Este algoritmo esta implemnetado en Invernadero.h.

## SICT0301B: Evalúa los componentes.

## SICT0303B: Implementa acciones científicas.

## Referencias:
#### Quick Sort In C++ With Examples. (2023, June 18). Software Testing Help. https://www.softwaretestinghelp.com/quick-sort/
#### c++ Ordenamiento QuickSort. (2021, October 6). c++ Ordenamiento QuickSort. Stack Overflow En Español. https://es.stackoverflow.com/questions/488722/c-ordenamiento-quicksort
#### C Program for QuickSort. (2014, January 7). GeeksforGeeks; GeeksforGeeks. https://www.geeksforgeeks.org/cpp-program-for-quicksort/

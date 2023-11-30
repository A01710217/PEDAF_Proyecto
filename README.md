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

#### Se agrego un archivo test.cpp:
###### En el archivo se crearon casos, provando lafuncionalidad de los metodos mas importantes:
- void agregarFlor(T); 
- int search(T); 
- void update(int, T); 
- void deleteAt(int); 
- void quicksort();
- void clear();

## SICT0301B: Evalúa los componentes.

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

##### Análisis asintótica del metodo quicksort().
- void quicksort(); es de complejidad O(nlog(n)), aunque mi peor caso es cuando el pivote no es el adecuado ya que esto hace que el algoritmo sea de O(n²) 

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.

##### Análisis asintótica de los metodos de "Invernadero.h":
- bool empty() const; es O(1) ya que solo evalua si el head es 0.
- void clear(); es O(n) debido a que tiene un ciclo while, n dependera de los datos que tenga la linked list
- void agregarFlor(T); es O(n) debido a un for para hacer que las palabras tengan letras minusculas, n dependera de los caracteres que tenga la palabra.
- int search(T); es O(n) debido a que tiene dos ciclos un while y un for pero no estan anidados, estan en el mismo nivel, la n del for dependera de los caracteres que tenga la palabra, y la del while dependera de donde esta ubicada la flor/palabra.
- int getTamno(); es O(n) debido a que tiene un ciclo while que recorre toda la linked list y obtiene el tamaño, n dependera del tamaño de la linked list.
- Link<T>* getUltimo(); es O(n) debido a que tiene un ciclo while que recorre toda la linked list y obtiene el ultimo valor, n dependera del tamaño de la linked list.
- T imprimirInvernaderoArchivo() const; es O(n) solo tiene un while que llena un stringstream, n dependera del tamaño de la linked list.
- T imprimirInvernadero() const; es O(n) solo tiene un while que llena un stringstream, n dependera del tamaño de la linked list.


### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

##### Análisis asintótica del main.cpp:
- int main(); es O()
- 

## SICT0302B: Toma decisiones.

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

##### Usé el algoritmo de ordenamiento Quick sort, este algoritmo organiza nombres de flores de la A a la Z. Este algoritmo esta implemnetado en Invernadero.h en las lineas 138 a 175

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

##### Usé una "Linked list", debido a que la cantidad de datos son 130. Para esta cantidad nesesitaba una estructura donde la inserciónn y la eliminación son sensillas y eficientes. También me son de utilidad debido a que la asignación de memoria dinámica y puedo agregar tantoas datos como lo nesesite el registro. 



## SICT0303B: Implementa acciones científicas.

### Implementa mecanismos para consultar información de las estructras correctos.

#####

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

#####

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.

#####


## Referencias:
#### Quick Sort In C++ With Examples. (2023, June 18). Software Testing Help. https://www.softwaretestinghelp.com/quick-sort/
#### c++ Ordenamiento QuickSort. (2021, October 6). c++ Ordenamiento QuickSort. Stack Overflow En Español. https://es.stackoverflow.com/questions/488722/c-ordenamiento-quicksort
#### C Program for QuickSort. (2014, January 7). GeeksforGeeks; GeeksforGeeks. https://www.geeksforgeeks.org/cpp-program-for-quicksort/

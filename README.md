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
- Retroalimentación del avance 3

#### Análisis asintótica del archivo "Invernadero.h":
- void agregarFlor(T); O(n)
- int search(T); O(n)
- void update(int, T); O(n)
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

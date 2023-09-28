# Registro de invernadero.

### Este proyecto es un catálogo de nombres de flores (strings).

#### En el cual habarcare estos puntos:
- Un "cout" del registro del invernadero.
- Un .push_back() a un vector, que añada nombres (strings) de flores.
- Un metodo de ordenamiento, por el metodo de "selección de ordenamiento".
- Y un metodo de busqueda binaria, buscar flores en el invernadero.
- Un opcción que te permita llenar el arreglo con un archivo .txt.

#### Proximamente:
- Usar el metodo de "Quick sort".

#### Análisis asintótica del archivo "Invernadero.h":
- void intercambiarFlores(std::vector<std::string> &, int, int); O(n)
- int bs_aux(std::vector<std::string> &, int, int, std::string val); O(n)

- std::vector<std::string>& getInvernadero(); 
- void agregarFlor(std::string &flor); O(n)
- void imprimirInvernadero(); O(n)
- void ordenaSeleccion(std::vector<std::string> &); O(n)
- int busqBinaria(const std::vector<std::string> &, const std::string &); O(n)

// =========================================================
// Nombre: test.cpp
// Autor: Axel Camacho Villafuerte.
// Fecha: 27/11/2023.
// Versión: 1.0.0.
// Descripción: Probar funcionalidades del Invernadero.h.
// =========================================================

#include <iostream>

#include "Invernadero.h"

using namespace std;

int main() {
	Invernadero<string> pruebaI;
	string ans;

	pruebaI.agregarFlor("tulipanes");
	ans = "[tulipanes]";
	cout <<"1.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.agregarFlor("ROSAS");
    pruebaI.agregarFlor("gIrASoLES");
	pruebaI.agregarFlor("Orquideas");

	pruebaI.quicksort();
	ans = "[girasoles, orquideas, rosas, tulipanes]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	cout << "\n" <<"3.- esperada " << 2 << " programa " << pruebaI.search("Rosas") << "\n";
	cout <<	(2 == pruebaI.search("Rosas") ? "success\n" : "fail\n");
	cout << "\n" <<"4.- esperada " << -1 << " programa " << pruebaI.search("Petunia") << "\n";
	cout <<	(-1 == pruebaI.search("Petunia") ? "success\n" : "fail\n");

	pruebaI.deleteAt(1);
	ans = "[girasoles, rosas, tulipanes]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.agregarFlor("clavel");

	pruebaI.quicksort();
	ans = "[clavel, girasoles, rosas, tulipanes]";
	cout << "\n" <<"5.1.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.deleteAt(2);
	ans = "[clavel, girasoles, tulipanes]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout << (!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.agregarFlor("Alcatraces");

	pruebaI.quicksort();
	ans = "[alcatraces, clavel, girasoles, tulipanes]";
	cout << "\n" <<"6.1.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout << (!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.deleteAt(0);
	ans = "[clavel, girasoles, tulipanes]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.deleteAt(1);
	ans = "[clavel, tulipanes]";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

    cout << "\n" <<"9.- esperada " << -1 << "\n programa " << pruebaI.search("lirios") << "\n";
    cout <<	(-1 == pruebaI.search("lirios") ? "success\n" : "fail\n");

    cout << "\n" <<"10.- esperada " << 1 << "\n programa " << pruebaI.search("tulipanes") << "\n";
    cout <<	(1 == pruebaI.search("tulipanes") ? "success\n" : "fail\n");

    pruebaI.clear();
    ans = "[]";
    cout << "\n" <<"11.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
    cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");
}

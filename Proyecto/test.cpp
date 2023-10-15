// =========================================================
// Nombre: test.cpp
// Autor: Axel Camacho Villafuerte.
// Fecha: 15/10/2023.
// Versión: 0.0.5.
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
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.agregarFlor("ROSAS");
    pruebaI.agregarFlor("gIrASoLES");
	pruebaI.agregarFlor("Orquideas");
	ans = "[tulipanes, rosas, girasoles, orquideas]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	cout << "\n" <<"3.- esperada " << 1 << " programa " << pruebaI.search("Rosas") << "\n";
	cout <<	(1 == pruebaI.search("Rosas") ? "success\n" : "fail\n");
	cout << "\n" <<"4.- esperada " << -1 << " programa " << pruebaI.search("Petunia") << "\n";
	cout <<	(-1 == pruebaI.search("Petunia") ? "success\n" : "fail\n");

	pruebaI.update(1, "Lirios");
	ans = "[tulipanes, lirios, girasoles, orquideas]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.update(3, "Clavel");
	ans = "[tulipanes, lirios, girasoles, clavel]";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout << (!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.deleteAt(0);
	ans = "[lirios, girasoles, clavel]";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

	pruebaI.deleteAt(1);
	ans = "[lirios, clavel]";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
	cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");

    cout << "\n" <<"9.- esperada " << -1 << "\n programa " << pruebaI.search("tulipanes") << "\n";
    cout <<	(-1 == pruebaI.search("tulipanes") ? "success\n" : "fail\n");

    cout << "\n" <<"10.- esperada " << 1 << "\n programa " << pruebaI.search("clavel") << "\n";
    cout <<	(1 == pruebaI.search("clavel") ? "success\n" : "fail\n");

    pruebaI.clear();
    ans = "[]";
    cout << "\n" <<"11.- esperada " << ans << "\n programa " << pruebaI.imprimirInvernadero() << "\n";
    cout <<	(!ans.compare(pruebaI.imprimirInvernadero()) ? "success\n" : "fail\n");
}
#include "trie.h"

using namespace std;

int main() {
  Trie arbol1;

  arbol1.insertarPalabra("Hola");
  arbol1.insertarPalabra("Prueba");
  arbol1.insertarPalabra("Buenas");

  if (arbol1.buscarPalabra("Hola")) {
    cout << "True\n";
  } else {
    cout << "False\n";
  }
  if (arbol1.buscarPalabra("Prueba")) {
    cout << "True\n";
  } else {
    cout << "False\n";
  }
  if (arbol1.buscarPalabra("Buenas")) {
    cout << "True\n";
  } else {
    cout << "False\n";
  }

  return 0;
}
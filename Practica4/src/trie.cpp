#include "trie.h"

using namespace std;

Celda::Celda() {
  caracter = '\0';
  padre = nullptr;
  hijo_izq = nullptr;
  herm_der = nullptr;
}

Celda::~Celda() {
  caracter = '\0';
  padre = nullptr;
  hijo_izq = nullptr;
  herm_der = nullptr;
}

Celda::Celda(char caracter) {
  Celda();
  this->caracter = caracter;
}

Celda::Celda(const Celda &c) {
  *this = c;
}

Celda &Celda::operator=(const Celda &c) {
  caracter = c.caracter;
  padre = c.padre;
  hijo_izq = c.hijo_izq;
  herm_der = c.herm_der;
  return *this;
}

Trie::Trie() {
  raiz = new Celda();
}

Trie::Trie(string palabra) {
  Trie();
  insertarPalabra(palabra);
}

Trie::~Trie() {
  if (raiz != nullptr) {
    podar(raiz);
  }
  raiz = nullptr;
}

Nodo Trie::insertarCaracter(char c, Nodo n) {
  if (n->padre != nullptr) {
    if (n->caracter == '\0') {
      n->caracter = c;
    } else if (n->caracter != c) {
      if (n->herm_der != nullptr) {
        return insertarCaracter(c, n->herm_der);
      } else {
        n->herm_der = new Celda(c);
        n->herm_der->padre = n->padre;
        return n->herm_der;
      }
    }
  } else {
    if (n->hijo_izq != nullptr) {
      return insertarCaracter(c, n->hijo_izq);
    } else {
      n->hijo_izq = new Celda(c);
      n->hijo_izq->padre = n;
      return n->hijo_izq;
    }
  }
  return n;
}

string Trie::toLowerString(string str) {
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == ' ') {
      continue;
    }

    else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = tolower(str[i]);
    }
  }

  return str;
}

void Trie::insertarPalabra(string palabra) {
  Nodo n = raiz;
  Nodo aux;
  palabra = toLowerString(palabra);
  palabra += '\n';
  for (char c : palabra) {
    if (n->hijo_izq == nullptr) {
      n->hijo_izq = new Celda();
      n->hijo_izq->padre = n;
      aux = n->hijo_izq;
    } else if ((buscarCaracter(c, n->hijo_izq)) != nullptr) {
      n = buscarCaracter(c, n->hijo_izq);
      continue;

    } else if (n->herm_der == nullptr && n->padre != nullptr) {
      aux = n;

    } else if (buscarCaracter(c, n->herm_der) != nullptr) {
      n = buscarCaracter(c, n->herm_der);
      continue;

    } else {
      if (n->padre == nullptr) {
        n = n->hijo_izq;
      }
      aux = crearHermanoDerecho(n);
    }
    n = insertarCaracter(c, aux);
  }
}

Nodo Trie::crearHermanoDerecho(Nodo n) {
  while (n->herm_der != nullptr) {
    n = n->herm_der;
  }

  n->herm_der = new Celda();
  n->herm_der->padre = n->padre;
  return n->herm_der;
}

Nodo Trie::getHermanoIzquierdo(Nodo n) {
  Nodo aux = n;

  if (n->padre->hijo_izq != n && n->padre != nullptr) {
    aux = n->padre->hijo_izq;
    while (aux->herm_der != n) {
      aux = aux->herm_der;
    }
  }

  return aux;
}

bool Trie::estaVacio() {
  return (raiz->hijo_izq == nullptr);
}

Nodo Trie::buscarCaracter(char c, Nodo n) {
  if (n != nullptr && n->caracter != c) {
    if (n->herm_der != nullptr)
      return buscarCaracter(c, n->herm_der);
  }

  return n;
}

bool Trie::buscarPalabra(string palabra) {
  if (estaVacio()) {
    return false;
  }

  Nodo n = raiz;
  char c;
  palabra = toLowerString(palabra);
  palabra += '\n';
  for (size_t i = 0; i < palabra.size(); i++) {
    c = palabra[i];
    n = buscarCaracter(c, n->hijo_izq);

    if (n == nullptr) {
      return false;
    }
  }
  return true;
}

void Trie::podar(Nodo n) {
  Nodo aux;

  if (n == nullptr) {
    return;
  }

  if (n->hijo_izq != nullptr) {
    podar(n->hijo_izq);
  }

  if (!estaVacio()) {
    if (n->padre->hijo_izq == n) {
      n->padre->hijo_izq = n->herm_der;

    } else {
      aux = getHermanoIzquierdo(n);
      aux->herm_der = n->herm_der;
    }
  }
  delete n;
}

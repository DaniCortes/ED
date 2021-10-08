#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Nodo{};

void rp_recursivo(Nodo v) {
   marca[v] = VISITADO;
   for(Nodo w: adyacentes) {
      if (marca[w] == NOVISITADO)
         rp(w);
   }   
}

void rp(Nodo v) {
   stack<Nodo> cc;
   cc.push(v);
   while (!cc.empty()) {
      v = cc.top();
      cc.pop();
      marca[v] = VISITADO;
      for (Nodo w : adyacentes) {
         if (marca[w] == NOVISITADO) {
            cc.push(w);
         }
      }
   }
}

void ra(Nodo v) {
   queue<Nodo> cc;
   marca[v] = VISITADO;
   cc.push(v);
   while (!cc.empty()) {
      v = cc.front();
      cc.pop();
      for (Nodo w : adyacentes) {
         if (marca[w] == NOVISITADO) {
            marca[w] = VISITADO;
            cc.push(w);
         }
      }
   }
}
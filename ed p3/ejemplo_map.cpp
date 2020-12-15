// constructing maps
#include <iostream>
#include <map>

using namespace std;

void imprime_guia(const map<string, string> &g) {
   cout << "Guia: " << endl;
   for (map<string, string>::const_iterator it = g.begin(); it != g.end(); ++it) {
      cout << "\t" << it->first << " -- " << it->second << endl;
   }
   cout << endl;
}

int main() {
   map<string, string> guia;

   guia["Luisa"] = "655444555";
   guia["Pedro"] = "666555444";
   guia["Ilias"] = "654777555";
   guia["Zulair"] = "622334455";

   imprime_guia(guia);

   cout << "Tambien puedo acceder a entradas usando su llave:" << endl;
   cout << "El numero de Ilias es: " << guia["Ilias"] << endl;

   cout << "Intento insertar otra vez a Pedro: " << endl;
   guia.insert(pair<string, string>("Pedro", "111111"));

   imprime_guia(guia);

   cout << "Ha insertado otra vez a Pedro? no? " << endl;

   cout << "Vamos a analizar qué devuelve insert: " << endl;

   pair<map<string, string>::iterator, bool> valor_devuelto;
   valor_devuelto = guia.insert(pair<string, string>("Pedro", "111111"));

   if (valor_devuelto.second == false) {
      cout << "El elemento " << valor_devuelto.first->first << " ya existe";
      cout << " con teléfono " << valor_devuelto.first->second << endl;
   } else {
      cout << "Inserción realizada con éxito" << endl;
   }

   cout << endl;

   cout << "Ahora busco a un contacto de la lista: está Ilias? " << endl;
   map<string, string>::iterator it = guia.find("Ilias");
   if (it != guia.end()) {
      cout << "He encontrado a Ilias, su telefono es: " << it->second << endl;
   } else {
      cout << "No he encontrado a Ilias" << endl;
   }

   cout << endl;

   cout << "Creo una nueva guía como copia de la anterior, desde la letra M hasta el final: " << endl;
   map<string, string> guiaM_Z(guia.lower_bound("M"), guia.end());
   imprime_guia(guiaM_Z);

   return 0;
}

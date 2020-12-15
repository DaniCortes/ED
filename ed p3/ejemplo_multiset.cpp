#include <iostream>
#include <set>				// OJO: include <set> también para usar el contenedor multiset de la STL
using namespace std;

struct ordenPropio {
  bool operator() (const string& a, const string& b) const
  {return a>b;}
};
 
int main() {

	multiset<string> conjunto; 

	//inserciones en el conjunto:
	conjunto.insert("perro");
	conjunto.insert("gato");
	conjunto.insert("perro");
	conjunto.insert("paloma");
	conjunto.insert("elefante");

	//comprobamos número de elementos (se ha insertado "perro" dos veces?):
	cout<<"conjunto tiene almacenados "<< conjunto.size()<<" elementos"<<endl;

	//eliminamos "elefante"
	conjunto.erase("elefante");
	cout<<"conjunto tiene almacenados "<< conjunto.size()<<" elementos"<<endl;

	//trabajamos con iteradores: 
	multiset<string>::iterator it; 
	it = conjunto.find("perro");
	if (it != conjunto.end())
		cout << "conjunto SI contiene la palabra 'perro'. Está apuntada por it: "<< *it <<endl; 
	else
		cout << "conjunto NO contiene la palabra 'perro'"<<endl; 

	
	cout << "Cuántas veces aparece 'perro'?"<<endl;
	it = conjunto.lower_bound("perro");
	multiset<string>::iterator it2 = conjunto.upper_bound("perro");
	cout << "'perro' aparece "<< distance(it, it2) << " veces"<<endl;
	cout << "Recorremos todas las ocurrencias de perro: "<<endl;
	while (it != it2){
		cout << *it<<", ";
		++it;
	}
	cout << endl;


	cout<< "Imprimo todos los elementos del conjunto, recorro con iterador: "; 
	for (it= conjunto.begin(); it!= conjunto.end(); ++it){
		cout << *it << " ";
	}
	cout <<endl; 

	cout << "Se guardan los elementos ordenados? cuál es el orden?" <<endl;

	cout << "Creo otro multiset por copia del primero, pero este multiset tiene otro criterio de ordenación"<<endl;
	multiset<string,ordenPropio> conjunto2 (conjunto.begin(), conjunto.end());
	cout<< "Imprimo todos los elementos de este nuevo multiset: "; 
	for (it= conjunto2.begin(); it!= conjunto2.end(); ++it){
		cout << *it << " ";
	}
	cout <<endl; 



}

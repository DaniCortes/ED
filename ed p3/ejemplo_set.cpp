#include <iostream>
#include <set>				// para usar el contenedor set de la STL
#include <cstdlib>			// para usar funcion rand()
using namespace std;

// ignora la siguiente línea, de momento, luego veremos para qué se usa: 
 #include <unordered_set>

 
int main() {

	set<string> conjunto; 

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
	set<string>::iterator it; 
	it = conjunto.find("perro");
	if (it != conjunto.end())
		cout << "conjunto SI contiene la palabra 'perro'. Está apuntada por it: "<< *it <<endl; 
	else
		cout << "conjunto NO contiene la palabra 'perro'"<<endl; 



	cout<< "Imprimo todos los elementos del conjunto, recorro con iterador: "; 
	for (it= conjunto.begin(); it!= conjunto.end(); ++it){
		cout << *it << " ";
	}
	cout <<endl; 

	cout << "Se guardan los elementos ordenados? cuál es el orden?" <<endl;

	cout << "Otro experimento para comprobar el orden, ahora con conjunto de enteros:"<<endl; 
	set<int> conjunto2; 

	cout << "Inserto ahora 10 números enteros aleatorios entre 0 y 99..."<<endl;
	for (int i=1; i<=10; i++){
		int num = rand() % 100;  
		conjunto2.insert(num);
	}
	cout << "Recorro el conjunto con un iterador, desde begin() hasta end(): "<<endl; 
	for (set<int>::iterator it2 = conjunto2.begin(); it2!= conjunto2.end(); ++it2){
		cout << *it2 << " ";
	}
	cout << endl; 
	cout << "cuál es el orden en un set?"<<endl; 

	cout << "Dónde iría el elemento 55? "<<endl; 
	set<int>::iterator it2 = conjunto2.lower_bound(55);			//lower_bound() me devuelve un iterador a la posición que ocuparía el elemento
	cout << "Esa posición está actualmente ocupada por: "<<*it2<<endl; 



	// Si queremos usar un set en el que los elementos NO estén ordenados, se emplea unordered_set. 
	// Esta clase está en la STL, pero sólo a partir del estándar C++11 (necesitas añadir el flag -std=c++11 para compilar)
	// Para que el resto del código funcione: 
	// 1.- Descomenta arriba el #include <unordered_set>
	// 2.- Descomenta las líneas siguientes
	// 3.- Compila haciendo: g++ -o ejemplo_set ejemplo_set.cpp -std=c++11

	unordered_set<int> conjunto3; 
	cout << "Ahora con unordered_set. Inserto 10 números enteros aleatorios entre 0 y 99..."<<endl;
	for (int i=1; i<=10; i++){
		int num = rand() % 100;  
		conjunto3.insert(num);
	}
	cout << "Recorro el conjunto con un iterador, desde begin() hasta end(): "<<endl; 
	for (unordered_set<int>::iterator it3 = conjunto3.begin(); it3!= conjunto3.end(); ++it3){
		cout << *it3 << " ";
	}
	cout << endl; 
	cout << "cuál es el orden en un unordered_set?"<<endl; 


}

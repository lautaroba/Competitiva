#include <bits/stdc++.h>

using namespace std;

struct Trie // La complejidad del Trie de crear es es Log (n) * tamaño del string ,por el insert del map
{ 			// ahora, la busqueda es O(n), lo cual es muy util para un sistema de querys
	bool esta;

	map<char,Trie> hijos;  //cantidad de nodos posibles {A ... Z}

	Trie() { 		// constructor q inicializa las varibles de un nodo
		esta = false; 
	}
	// funcion insertar un nuevo string
	void insertar(const string &s, int pos){
		if (pos < int(s.size()))
			hijos[s[pos]].insertar(s,pos+1);
		else
				esta = true;
	}
	// si no recibe el parametro pos
	void insertar(const string &s){
		insertar(s, 0);
	}
	// funcion buscar si existe un string
	bool buscar(const string &s, int pos) {
		if(pos < int(s.size())){
			return hijos.find(s[pos]) != hijos.end() and hijos[s[pos]].buscar(s,pos+1);
		}
		else{
			return esta;
		}
	}
	// si no recibe el parametro pos
	bool buscar(const string &s) {
		return buscar(s, 0);
	}
	
};

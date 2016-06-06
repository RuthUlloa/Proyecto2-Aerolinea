#ifndef VERTICE_H
#define VERTICE_H
#include <stdexcept>

using namespace std;

class Vertice{

private:

    int numVertice;
    string nombre;


public:
    Vertice(){}

    Vertice(string x, int n){ // inicializa el nombre y el número de vértice
         nombre = x;
         numVertice = n;
     }

     string getVertice(){ // retorna el nombre del vértice
        return nombre;
     }

     void setVertice(string nom){ // cambia el nombre del vértice
        nombre = nom;
     }

     bool isIgual(string n){ // decide entre la igualdad de nombres
        return nombre == n;
     }

     void setNumVertice(int n){ // cambia el número del vértice
        numVertice = n;
     }

     int getNumVertice(){ // retorna el número del vértice
        return numVertice;
     }

};
#endif // VERTICE_H

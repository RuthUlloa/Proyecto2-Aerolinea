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

    Vertice(string x, int n){ // inicializa el nombre y el n�mero de v�rtice
         nombre = x;
         numVertice = n;
     }

     string getVertice(){ // retorna el nombre del v�rtice
        return nombre;
     }

     void setVertice(string nom){ // cambia el nombre del v�rtice
        nombre = nom;
     }

     bool isIgual(string n){ // decide entre la igualdad de nombres
        return nombre == n;
     }

     void setNumVertice(int n){ // cambia el n�mero del v�rtice
        numVertice = n;
     }

     int getNumVertice(){ // retorna el n�mero del v�rtice
        return numVertice;
     }

};
#endif // VERTICE_H

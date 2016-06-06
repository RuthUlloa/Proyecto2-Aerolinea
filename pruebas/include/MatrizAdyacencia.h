#ifndef MATRIZADYACENCIA_H
#define MATRIZADYACENCIA_H
#include "Vertice.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#define INFINITO -1

using namespace std;

class MatrizAdyacencia
{
 private:
     int maxVertices; // máximo numero de vértices
     int numVertices; // número de vértices actual
     Vertice *vertices; // array de vértices
     int **matriz; // matriz de adyacencia
     int *raizKruskal;

public:
     typedef int *pint; // para el dimensionamiento de la matriz

     MatrizAdyacencia(int max){
          maxVertices = max;
          vertices = new Vertice[max]; // vector de vertices
          matriz = new pint[max]; // vector de punteros
          numVertices = 0;
          for (int i = 0; i < max; i++){
            matriz[i] = new int [max]; // matriz de adyacencia
            for (int j=0; j<max;j++){
              matriz[i][j] = INFINITO;
            }
          }
     }

     MatrizAdyacencia(){
          maxVertices = 1 ;
          MatrizAdyacencia(maxVertices);
     }

     int getNumeroDeVertices(){
         return numVertices;
     }

     void setNumeroDeVertices(int n){
         numVertices = n;
     }

     void nuevoVertice (string nom){
          bool esta = numVertice(nom) >= 0;
          if (!esta){
                if (numVertices<maxVertices){
                  Vertice v = Vertice(nom, numVertices);
                  vertices[numVertices++] = v; // se asigna a la lista.
                  // No se comprueba que sobrepase el máximo
                    }else{
                    cout << "Error, numero maximo de vertices." << endl;
                    }
          }else{
            cout << "Error, la ciudad ya existe." << endl;
          }
     }

     bool existe(string nom){
        return numVertice(nom) >= 0;
     }

     int numVertice(string v){
          int i;
          bool encontrado = false;
          for ( i = 0; (i < numVertices) && !encontrado;){
          encontrado = vertices[i].isIgual(v);
          if (!encontrado) i++ ;
          }
          return (i < numVertices) ? i : -1 ;
     }

     void nuevoArco(string a, string b, int valor){
          int va;
          int vb;
          va = numVertice(a);
          vb = numVertice(b);
          if (va < 0 || vb < 0) throw "Vértice no existe";
          matriz[va][vb] = valor;
     }

     void nuevoArco(int va, int vb){
          if (va < 0 || vb < 0 || va > numVertices || vb > numVertices)
          throw "Vértice no existe";
          matriz[va][vb] = 1;
     }

     void nuevoArco(int va, int vb, int valor){
          if (va < 0 || vb < 0 || va > numVertices || vb > numVertices)
          throw "Vértice no existe";
          matriz[va][vb] = valor;
     }

     bool isAdyacente(string a, string b){
          int va, vb;
          va = numVertice(a);
          vb = numVertice(b);
          if (va < 0 || vb < 0) throw "Vértice no existe";
          return matriz[va][vb] != INFINITO;
     }

     bool isAdyacente(int va, int vb){
          if (va < 0 || vb < 0 || va >= numVertices || vb >= numVertices)
          throw "Vértice no existe";
          return matriz[va][vb] != INFINITO;
     }

     int getValor(string a, string b){
          int va, vb;
          va = numVertice(a);
          vb = numVertice(b);
          if (va < 0 || vb < 0)throw "Vértice no existe";
          return matriz[va][vb];


     }

     int getValor( int va, int vb){
          if (va < 0 || vb < 0 || va >= numVertices || vb >= numVertices)
          throw "Vértice no existe";
          return matriz[va][vb];
     }

     void setValor(int va, int vb, int v){
          if (va < 0 || vb < 0 || va >= numVertices || vb >= numVertices)
              throw "Vértice no existe";
               matriz[va][vb] = v;
     }

      void setValor( char *a, char *b, int v){
           int va, vb;
           va = numVertice(a);
           vb = numVertice(b);
           if (va < 0 || vb < 0) throw "Vértice no existe";
           matriz[va][vb] = v;
      }


    Vertice getVertice(int va){
         if (va < 0 || va >= numVertices)
         throw "Vértice no existe";
         else return vertices[va];
    }

    void setVertice( int va, Vertice vert){
         if (va < 0 || va >= numVertices)
         throw "Vértice no existe";
         else vertices[va] = vert;
    }


    void print() {
       for (int i = 0; i < numVertices; i++) {
           for (int j = 0; j < numVertices; j++) {
               cout << " " << matriz[i][j] << " ";
           }
           cout << endl;
       }
       cout << endl;

    }

    void floyd(){
        typedef int *mint;
        typedef int *jint;

        int **matrizTemp;
        matrizTemp = new mint[numVertices];
        for (int i = 0; i < numVertices; i++){
            matrizTemp[i] = new int [numVertices]; // matriz de adyacencia
            for (int j = 0 ; j < numVertices; j++){
                if(i == j){
                    matrizTemp[i][j] = 0;
                }else{
                    matrizTemp[i][j] = matriz[i][j];
                }
            }
        }
        int **rutas;
        rutas = new jint[numVertices];
        for (int i = 0; i < numVertices; i++){
            rutas[i] = new int [numVertices]; // matriz de adyacencia
            for (int j = 0 ; j < numVertices; j++){
              rutas[i][j] = i;
            }
        }

        for (int i = 0; i < numVertices; i++) {
            for (int r = 0; r < numVertices; r++) {
                for (int c = 0; c < numVertices; c++) {

                    if (r != i && c != i && r != c) {
                        int temp;
                        int tempArco;

                        if(matrizTemp[r][i] == -1 || matrizTemp[i][c] == -1){
                            temp = matrizTemp[r][c] + 1;
                        } else{
                            temp = matrizTemp[r][i] + matrizTemp[i][c];
                        }

                        if(matrizTemp[r][c] == -1){
                            tempArco = temp + 1;
                        }else{
                            tempArco = matrizTemp[r][c];
                        }
                        if(matrizTemp[r][i] == -1 && matrizTemp[r][c] == -1 || matrizTemp[i][c] == -1 && matrizTemp[r][c] == -1){
                            temp = 1;
                            tempArco = -1;
                        }

                        if (temp < tempArco) {
                            matrizTemp[r][c] = temp;
                            rutas[r][c] = i;
                        }
                    }
                }
            }
            cout << "-Tabla de Pesos-" << endl;
            cout << endl;
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    cout << " " << matrizTemp[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            cout << "-Tabla de Rutas-" << endl;
            cout << endl;
            for (int i = 0; i < numVertices; i++) {
                for (int j = 0; j < numVertices; j++) {
                    cout << " " << rutas[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

    }

    void prim(){
        int longMin = 0;
        typedef int *pint;
        int **T = new pint [numVertices];
        for ( int i = 0 ; i < numVertices; i++){
            T[i] = new int [numVertices];
            for(int j = 0; j < numVertices; j++){
                T[i][j] = INFINITO;
            }
        }

        int menor;
        int i, j, z;
        int *coste = new int [numVertices];
        int *masCerca = new int [numVertices];
        bool *W = new bool [numVertices];
        for (i = 0; i < numVertices; i++)
            W[i] = false; // conjunto vacío
        W[0] = true; //se parte del vértice 0
        // inicialmente, coste[i] es la arista (0,i)
        for (i = 1; i < numVertices; i++){
            coste[i] = matriz[0][i];
            masCerca[i] = 0;
        }
        coste[0] = INFINITO;
        for (i = 1; i < numVertices; i++){// busca vértice z de V-W mas cercano,
         // de menor longitud de arista, a algún vértice de W
             menor = coste[1];
             z = 1;

             for (j = 2; j < numVertices; j++){
                 int temp;
                 int tempMenor;
                 if(coste[j] == -1 && menor >=0){
                   temp = menor + 1;
                   tempMenor = menor;

                 }else if(menor == -1 && coste[j] >= 0){
                   tempMenor = coste[j] + 1;
                   temp = coste[j];

                 }else if (menor == -1 && coste[j] == -1) {
                   temp = -1;
                   tempMenor = -1;

                 }else{
                   temp = coste[j];
                   tempMenor = menor;
                }
                if (temp < tempMenor ){
                     menor = coste[j];
                     z = j;
               }
             }
            longMin += menor;
         // se escribe el arco incorporado al árbol de expansión
         string origen = getVertice(masCerca[z]).getVertice();
         string destino = getVertice(z).getVertice();
         cout << origen <<  " -> "<< destino << " : " << coste[z] << endl;
         //cout << "V " << masCerca[z] <<  "-> V " << z;
         cout << "\n";
             W[z] = true; // vértice z se añade al conjunto W
             T[masCerca[z]][z] = T[z][masCerca[z]] = coste[z];
             coste[z] = INFINITO;

             // debido a la incorporación de z,
             // se ajusta coste[] para el resto de vértices
             int tempCoste;
             int tempMatriz;
             for (j = 1; j < numVertices; j++){
                if(matriz[z][j]==INFINITO && coste[j]==INFINITO){
                    tempCoste=INFINITO;
                    tempMatriz=INFINITO;

                }else if (matriz[z][j]==INFINITO && coste[j]>=0){
                     tempCoste=coste[j];
                    tempMatriz=coste[j]+1;

                }else if(matriz[z][j]>=0 && coste[j]==INFINITO){
                    tempCoste= matriz[z][j]+1;
                    tempMatriz= matriz[z][j];
                }else{
                    tempCoste=coste[j];
                    tempMatriz=matriz[z][j];
                }
                if (tempMatriz < tempCoste && !W[j]){
                    coste[j] = matriz[z][j];
                    masCerca[j] = z;
                }
             }
        }

        cout << "El costo minimo de todas las aristas del MST es : " << longMin << endl;
    }

    void dijkstra(int origen){

        int *ultimo = new int[numVertices];
        int *D = new int[numVertices];

        bool * F;
        F = new bool [numVertices];
         // valores iniciales
        for (int i = 0; i < numVertices; i++){
            F[i] = false;
            D[i] = matriz[origen][i];
            ultimo[i] = origen;
        }


        F[origen] = true;
        D[origen] = 0; //Marca origen e inicializa distancia
        // Pasos para marcar los n-1 vértices. Algoritmo voraz

        for (int p = 0; p < numVertices; p++){
            int v;
            double mx = -1; // valor de infinito
            //Busca el minimo de los pesos
            for (int j = 0; j < numVertices; j++){
                int temp;
                //verifica si hay algun infinito
                if(D[j] == -1 && mx >= 0){
                   temp = mx + 1;

                } else if(mx == -1 && D[j] >= 0){
                   mx = D[j] + 1;
                   temp = D[j];

                }else if (mx == -1 && D[j] == -1) {
                   temp = -1;

                }else{
                   temp = D[j];

                }

                if (!F[j] && (mx >= temp)){
                    mx = D[j];
                    v = j;
                }
            }

            F[v] = true;    //selecciona vértice no marcado de menor distancia

            // actualiza distancia de vértices no marcados
            for (int w = 0; w < numVertices; w++){
                int tempMatriz;
                int tempValor;
                if (!F[w]){
                    if (matriz[v][w] == -1 && D[w] == -1){
                        tempMatriz = -1;
                        tempValor = -1;

                    }else if (matriz[v][w] == -1 && D[w] >= 0){
                        tempMatriz = D[w] + 1;
                        tempValor = D[w];

                    }else if (matriz[v][w] >= 0 && D[w] == -1){
                        if(D[v] == -1){
                            tempMatriz = -1;
                            tempValor = -1;
                        }else{
                            tempMatriz = matriz[v][w] + D[v];
                            tempValor = (matriz[v][w] + D[v]) +1;
                        }
                    } else{
                        if(D[v] == -1){
                            tempMatriz = D[w] + 1;
                            tempValor = D[w];
                        }else{
                            tempMatriz = matriz[v][w] + D[v];
                            tempValor = D[w];
                        }

                    }

                    if (tempMatriz < tempValor){
                        D[w] = D[v] + matriz[v][w];
                        ultimo[w] = v;
                    }
                }

            }
            cout << D[p] << " ";
        }
        cout << endl << endl;
        for(int i = 0; i<4; i++){
            cout << ultimo[i] << " ";
        }
    }

//Método para encontrar la raiz del vértice actual X
    int FindKruskal( int x ){
        return ( x == raizKruskal[ x ] ) ? x : raizKruskal[ x ] = FindKruskal( raizKruskal[ x ] );
    }

    //Método para unir 2 componentes conexas
    void UnionKruskal( int x , int y ){
        raizKruskal[ FindKruskal( x ) ] = FindKruskal( y );
    }

    //Método que me determina si 2 vértices estan o no en la misma componente conexa
    bool mismoComponenteKruskal( int x , int y ){
        if( FindKruskal( x ) == FindKruskal( y ) ) return true;
        return false;
    }

    void kruskal(){

        typedef int *mint;
        int **matrizTemp;

        matrizTemp = new mint[numVertices];
        for (int i = 0; i < numVertices; i++){
            matrizTemp[i] = new int [numVertices]; // matriz de adyacencia
            for (int j = 0 ; j < numVertices; j++){
                matrizTemp[i][j] = matriz[i][j];

            }
        }

        int temp = 0;
        struct Arista{
            int origen;
            int peso;
            int destino;

            Arista(){}
            Arista(int i, int p, int j){ origen = i; peso = p; destino = j; }
            bool operator<( const Arista &e ) const{
                return peso < e.peso;
            }
        } aristas[numVertices*numVertices];
        Arista MST[numVertices*numVertices];

        //aristas = new Arista[numVertices*numVertices];
        int pesos[numVertices*numVertices];

        for (int i = 0; i< numVertices; i++){
            for(int j = 0; j<numVertices; j++){
                if (matrizTemp[i][j] != INFINITO){
                    aristas[temp] = Arista(i,matrizTemp[i][j],j);
                    pesos[temp]=matrizTemp[i][j];
                    temp += 1;
                }
            }

        }
        std::sort(pesos,pesos + temp);
        for(int i = 0; i<temp; i++){
            for (int j = i; j<temp; j++){
                if(aristas[j].peso == pesos[i]){
                    Arista tempArista = aristas[i];
                    aristas[i]= aristas[j];
                    aristas[j]=tempArista;
                    break;
                }
            }

        }

        /*for (int i = 0; i< temp; i++){
            cout << aristas[i].peso << endl;
        }*/

        raizKruskal = new int[temp];
          for( int i = 0 ; i <= temp ; i++ ){
            raizKruskal[ i ] = i;
          }

        int numAristas = 0;
        int total = 0;
        for( int i = 0 ; i < temp ; ++i ){     //Recorre las aristas ya ordenadas por peso
            //Verificamos si estan o no en la misma componente conexa
            if( !mismoComponenteKruskal( aristas[ i ].origen , aristas[ i ].destino ) ){  //Evito ciclos
                total += aristas[ i ].peso;              //Incremento el peso total del MST
                MST[ numAristas++ ] = aristas[ i ];  //Agrego al MST la arista actual
                UnionKruskal( aristas[ i ].origen , aristas[ i ].destino );  //Union de ambas componentes en una sola
            }
        }
        for( int i = 0 ; i < numAristas ; ++i )
        printf("( %d , %d ) : %d\n" , MST[ i ].origen , MST[ i ].destino , MST[ i ].peso ); //( vertice u , vertice v ) : peso

        printf( "El costo minimo de todas las aristas del MST es : %d\n" , total );



    }


};

#endif // MATRIZADYACENCIA_H

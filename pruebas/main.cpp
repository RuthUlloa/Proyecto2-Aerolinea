#include <iostream>
#include "include\MatrizAdyacencia.h"
#include <stdlib.h>

using namespace std;

crearGrafoDirigido(){
    int maximo;
    cout << endl;
    cout << "Digite la cantidad de ciudades a insertar: ";
    cin >> maximo;
    MatrizAdyacencia matriz(maximo);

    GrafoDirigido:
    cout << endl;
    cout << "|----- Digite la opcion que desea -----|"<< endl;
    cout << " + Insertar Ciudad (vertice) -> 1" << endl;
    cout << " + Crear ruta (arista) -> 2" << endl;
    cout << " + Ejecutar Algoritmo: Floyd -> 3" << endl;
    cout << " + Ejecutar Algoritmo: Dijsktra -> 4" << endl;
    cout << " + Regresar al menu principal -> 5" << endl;
    cout << "Opcion a elegir: ";
    int opcion;
    cin >> opcion;
    //variables case 1.
    string ciudad;
    //variables case 2.
    string ciudadOrigen;
    string ciudadDestino;
    //variables case 4.
    string origenDijkstra;
    int posicionDijkstra;
    int peso;
    switch(opcion){
        case 1:
            cout << endl;
            cout << "Digite el nombre de la ciudad: ";
            cin >> ciudad;
            matriz.nuevoVertice(ciudad);
            goto GrafoDirigido;

        case 2:
            cout << endl;
            cout << "Digite el nombre de la ciudad de origen: ";
            cin >> ciudadOrigen;
            if (matriz.existe(ciudadOrigen)){
                cout << endl;
                cout << "Digite el nombre de la ciudad de destino: ";
                cin >> ciudadDestino;
                if (matriz.existe(ciudadDestino)){
                    cout << endl;
                    cout << "Digite el peso: ";
                    cin >> peso;
                    if (peso>=0){
                        matriz.nuevoArco(ciudadOrigen,ciudadDestino,peso);
                        cout << "Arista creada con exito." << endl;
                        goto GrafoDirigido;
                    }else{
                        cout << "Error. Peso invalido.";
                        goto GrafoDirigido;
                    }
                }else{
                    cout << "Error. La ciudad de destino ingresada no existe." << endl;
                    goto GrafoDirigido;
                }
            }else{
                cout << "Error. La ciudad de origen ingresada no existe," << endl;
                goto GrafoDirigido;
            }
            break;
        case 3:
            cout << endl;
            cout << "- Algoritmo de Floyd -" << endl;
            cout << endl;
            matriz.floyd();
            goto GrafoDirigido;
        case 4:
            cout << endl;
            cout << "Escriba la ciudad de origen: ";
            cin >> origenDijkstra;
            posicionDijkstra = matriz.numVertice(origenDijkstra);
            if (posicionDijkstra>=0){
                cout << "- Algoritmo de Dijsktra -" << endl;
                cout << endl;
                matriz.dijkstra(posicionDijkstra);
                goto GrafoDirigido;
            }
            else{
                cout << "Error. La ciudad de origen no existe." << endl;
                goto GrafoDirigido;
            }
        case 5:
            break;
        default:
            goto GrafoDirigido;
    }

}

crearGrafoNoDirigido(){
    int maximo;
    cout << endl;
    cout << "Digite la cantidad de ciudades a insertar: ";
    cin >> maximo;
    MatrizAdyacencia matriz(maximo);

    GrafoNoDirigido:
    cout << endl;
    cout << "|----- Digite la opcion que desea -----|"<< endl;
    cout << " + Insertar Ciudad (vertice) -> 1" << endl;
    cout << " + Crear ruta (arista) -> 2" << endl;
    cout << " + Ejecutar Algoritmo: Prim -> 3" << endl;
    cout << " + Ejecutar Algoritmo: Kruskal -> 4" << endl;
    cout << " + Regresar al menu principal -> 5" << endl;
    cout << "Opcion a elegir: ";
    int opcion;
    cin >> opcion;

    //variables case 1.
    string ciudad;
    //variables case 2.
    string ciudadOrigen;
    string ciudadDestino;
    int peso;
    switch(opcion){
        case 1:
            cout << endl;
            cout << "Digite el nombre de la ciudad: ";
            cin >> ciudad;
            matriz.nuevoVertice(ciudad);
            goto GrafoNoDirigido;

        case 2:
            cout << endl;
            cout << "Digite el nombre de la ciudad de origen: ";
            cin >> ciudadOrigen;
            if (matriz.existe(ciudadOrigen)){
                cout << endl;
                cout << "Digite el nombre de la ciudad de destino: ";
                cin >> ciudadDestino;
                if (matriz.existe(ciudadDestino)){
                    cout << endl;
                    cout << "Digite el peso: ";
                    cin >> peso;
                    if (peso>=0){
                        matriz.nuevoArco(ciudadOrigen,ciudadDestino,peso);
                        matriz.nuevoArco(ciudadDestino,ciudadOrigen,peso);
                        cout << "Arista creada con exito." << endl;
                        goto GrafoNoDirigido;
                    }else{
                        cout << "Error. Peso invalido.";
                        goto GrafoNoDirigido;
                    }
                }else{
                    cout << "Error. La ciudad de destino ingresada no existe." << endl;
                    goto GrafoNoDirigido;
                }
            }else{
                cout << "Error. La ciudad de origen ingresada no existe," << endl;
                goto GrafoNoDirigido;
            }
            break;
        case 3:
            cout << endl;
            cout << "- Algoritmo de Prim -" << endl;
            cout << endl;
            matriz.prim();
            goto GrafoNoDirigido;
        case 4:
            cout << endl;
            cout << "- Algoritmo de Kruskal -" << endl;
            cout << endl;
            matriz.kruskal();
            goto GrafoNoDirigido;
        case 5:
            break;
        default:
            goto GrafoNoDirigido;
    }

}


int main()
{
    //esto es una prueba del repositorio :)
   int opcion = 4;
   //Menu:
   while(opcion == 4){
       cout << endl;
       cout << "|---------- Aerolinea ---------|" << endl;
       cout << " - Digite la opcion que desea - " << endl;
       cout << "   + Crear un grafo dirigido -> 1" << endl;
       cout << "   + Crear un grafo no dirigido -> 2" << endl;
       cout << "   + Salir -> 3" << endl;

       cout << "Opcion a elegir: ";
       cin >> opcion;
       if (!cin){
        cin.clear(); // Borrar la entrada fallida
        opcion = 4;
        }
       switch(opcion){
       case 1:
           crearGrafoDirigido();
           opcion = 4;
           break;
       case 2:
           crearGrafoNoDirigido();
           opcion = 4;
           break;
       case 3:
           cout << "Programa finalizado." << endl;
           exit(0);
       default:
           opcion = 4;
       }
   }
}



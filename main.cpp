//José Pablo Galindo Hernández A01276079
//Roberto Carlos Pedraza Miranda A01277764

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class CGrafo {
private:
    int V;
    vector<vector<pair<int, int>>> ListaAdyacencia;

public:
    CGrafo(int vertices) : V(vertices) {
        ListaAdyacencia.resize(V);
    }

    void Estaciones(int u, int v, int peso) {
        ListaAdyacencia[u].push_back(make_pair(v, peso));
        ListaAdyacencia[v].push_back(make_pair(u, peso));
    }

    pair<int, vector<int>> Dijkstra(int NodoInicio, int NodoFin) {
           vector<int> distancia(V, numeric_limits<int>::max());
           distancia[NodoInicio] = 0;
           vector<int> padre(V, -1);
           
           for (int i = 0; i < V - 1; ++i) {
               for (int u = 0; u < V; ++u) {
                   for (auto vecino : ListaAdyacencia[u]) {
                       int v = vecino.first;
                       int peso = vecino.second;
                       if (distancia[u] != numeric_limits<int>::max() && distancia[u] + peso < distancia[v]) {
                           distancia[v] = distancia[u] + peso;
                           padre[v] = u;
                       }
                   }
               }
           }

           vector<int> recorrido;
           int actual = NodoFin;
           while (actual != NodoInicio) {
               recorrido.push_back(actual);
               actual = padre[actual];
           }
           recorrido.push_back(NodoInicio);
           return make_pair(distancia[NodoFin], recorrido);
       }
   };


int main() {
    int opcion;
    int Estacionsalida;
    int Estacionllegada;
    int V = 15;
    CGrafo migrafo(V);

    migrafo.Estaciones(0, 1, 251);
    migrafo.Estaciones(0, 6, 335);
    migrafo.Estaciones(0, 9, 325);
    migrafo.Estaciones(0, 10, 395);
    migrafo.Estaciones(0, 12, 193);
    migrafo.Estaciones(1, 2, 191);
    migrafo.Estaciones(1, 3, 150);
    migrafo.Estaciones(2, 3, 241);
    migrafo.Estaciones(2, 7, 349);
    migrafo.Estaciones(3, 4, 278);
    migrafo.Estaciones(4, 5, 256);
    migrafo.Estaciones(4, 6, 99);
    migrafo.Estaciones(6, 5, 242);
    migrafo.Estaciones(7, 8, 100);
    migrafo.Estaciones(7, 9, 296);
    migrafo.Estaciones(9, 10, 324);
    migrafo.Estaciones(10, 11, 304);
    migrafo.Estaciones(10, 12, 280);
    migrafo.Estaciones(12, 13, 356);
    migrafo.Estaciones(12, 14, 455);
    migrafo.Estaciones(13, 14, 171);

    do {
        cout << "Seleccione una opción: \n";
        cout << "1.- Buscar recorrido más corto \n";
        cout << "2.- Ver Estaciones \n";
        cout << "3.- Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese la estación de salida: ";
                cin >> Estacionsalida;
                cout << "Ingrese la estación de llegada: ";
                cin >> Estacionllegada;
                
                pair<int, vector<int>> resultado = migrafo.Dijkstra(Estacionsalida, Estacionllegada);
                int distancia = resultado.first;
                vector<int> recorrido = resultado.second;

                if (distancia != -1) {
                    cout << "\nLa distancia mínima entre las estaciones es: " << distancia << endl;
                    cout << "El recorrido es: ";
                for (int estacion : recorrido) {
                    cout << estacion << " ";
                    
                }
                    cout << endl;
                    
                } else{
                    cout << "\nNo hay ruta entre las estaciones" << endl;
                    
                }
                break;
                
            }
            case 2: {
                cout << "0.- Pachuca de Soto\n";
                cout << "1.- Mineral de la Reforma\n";
                cout << "2.- Tulancingo\n";
                cout << "3.- Apan\n";
                cout << "4.- Tizayuca\n";
                cout << "5.- Tepeji del río\n";
                cout << "6.- Ajacuba\n";
                cout << "7.- Tenango de doria\n";
                cout << "8.- Huejutla de reyes\n";
                cout << "9.- Huasca de ocampo\n";
                cout << "10.- Actopan\n";
                cout << "11.- Molango de Escamilla\n";
                cout << "12.- Tula de Allende\n";
                cout << "13.- Zimapán\n";
                cout << "14.- Ixmiquilpan\n";
                break;
            }
            case 3: {
                cout << "Saliendo del programa\n";
                break;
            }
            default: {
                cout << "Opción inválida. Intente de nuevo." << endl;
            }
        }
    } while (opcion != 3);

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
typedef int Vertex;

/** enum Cor = {branco = 0, cinza = 1, preto = 2}; */

class Graph{
private:
vector <Vertex> *adj;
int n, m; /** Ordem(n) = número de vértices, tamanho(m) = número de arestas */
void destroy();
public:
Graph(int);
void initialize(int);
void insertEdge(Vertex, Vertex);
void print();
/** Getters e setters caso sejam necessários */
};

Graph:: Graph(int n){
    this->n=0;
    this->m=0;
    initialize(n);
}

void Graph::initialize(int n){
    if(this->n != 0) destroy();
    this->n = n;
    adj = new vector<Vertex>[n+1];
}

void Graph::insertEdge(Vertex u, Vertex v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    m++;
}

void Graph::print(){
    for(int i = 1; i <= n; i++){
        cout << "v[" <<  i << "] = ";
        for(int j = 0; j < adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::destroy(){
    adj->erase(adj->begin(), adj->end());
    delete(adj);
    n = m = 0;
}

void testaGrafo(Graph &g){
    g.insertEdge(1,2);
    g.insertEdge(2,3);
    g.insertEdge(3,4);
    g.insertEdge(4,5);
    g.insertEdge(5,1);
    g.insertEdge(5,2);
    g.insertEdge(2,4);
    g.print();
}

int main(int argc, const char* argv[]){
    int n = 5;
    Graph g(n);
    testaGrafo(g);

    return 0;
}

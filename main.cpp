#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "unionfind.h"

Graph graph;
Graph mst;

// Schritt 1: Interpretation
// 1.Zeile lesen => Array mit Knoten erstellen von 0 bis n-1
// nach der 1.Zeile: immer die ersten beiden Zahlen als Kante interpretieren(?)
// Graphendurchmusterung: zhg oder nicht => Abbruch, falls nicht
// die dritte Zahl als Gewicht der passenden Kante zuordnen
// m:= Anzahl der Kanten
// m-dimensionales Array der Laenge 3 a[i,0], a[i,1] Kante, a[i,2] Kosten fuer i=0,...,m-1
void einlesen(char *dateiname);

bool check_graph();

// Schritt 2: Sortierung: Sortiere Kanten nach Gewicht mit qsort bzw std::sort
void sortieren();

// Schritt 3: Union Find Kreise, Hinzufügen, Zhk verwalten
void union_find();

// Schritt 4: Ausgabe
void ausgeben(Graph &result);

//void union_find();

void einlesen(char *dateiname) {
    std::ifstream file;

    file.open(dateiname);

    if (file.is_open()){
        unsigned vertex_count;
        file>>vertex_count;

        graph.vertex_count = vertex_count;

        unsigned n = 0;

        Edge edge;
        int a,b,weight;

        while (!file.eof()) {
            file>>a>>b>>weight;

            edge.a=a;
            edge.b=b;
            edge.weight = weight;

            graph.edges.push_back(edge);

            n++;
        }

        graph.edge_count = n;

        file.close();
    }
    else {
        std::cerr<<"Fehler beim oeffnen der Datei!"<<std::endl;
    }
}

struct graph_weight
{
    inline bool operator() (const Edge& struct1, const Edge& struct2)
    {
        return (struct1.weight < struct2.weight);
    }
};

// todo prüfen, ob alle Knoten verbunden sind

bool check_graph() {
    make_set(graph.vertex_count);
    for(unsigned i=0;i<graph.edge_count;i++){
        unsigned long a=graph.edges[i].a;
        unsigned long b=graph.edges[i].b;
        Union(a,b);
    }
    unsigned long start=find(0);
    for (unsigned i=0;i<graph.vertex_count;i++){
        if (find(i)!=start){
            return false;
        }
    }
    return true;
}

void sortieren() {
    std::sort(graph.edges.begin(), graph.edges.end(), graph_weight());
}

int main(int argc,  char** argv) {
    if (argc != 2) {
        std::cout<<"Bitte geben Sie als Argument eine Datei an."<<std::endl;
        return 0;
    }

    einlesen(argv[1]);

    if (!check_graph()) {
        std::cout<<"Die Knoten sind nicht alle erreichbar."<<std::endl;
    }

    sortieren();

    union_find();

    ausgeben(mst);

    return 0;
}

void union_find() {
    make_set(graph.vertex_count);
    mst.edge_count = 0;
    for(unsigned i=0;i<graph.edge_count;i++){
        unsigned long a=graph.edges[i].a;
        unsigned long b=graph.edges[i].b;
        unsigned long fa = find(a);
        unsigned long fb = find(b);
        if (fa != fb){
            mst.edges.push_back(graph.edges[i]);
            mst.edge_count++;
            Union(a,b);
        }
    }
    mst.vertex_count = mst.edge_count+1;
}


void ausgeben(Graph &result) {
    int weight = 0;
    for (unsigned i=0; i < result.edge_count; i++){
        weight += result.edges[i].weight;
    }

    std::cout<<"The following is a minimum weight spanning tree with weight "<< weight << std::endl;
    std::cout<<"The graph contains vertices 0,...," << result.vertex_count - 1 << " and the following edges:"<<std::endl;

    for (unsigned i=0; i < result.edge_count; i++){
        std::cout<<"{" << result.edges[i].a << "," << result.edges[i].b << "} with weight " << result.edges[i].weight << std::endl;
    }
}


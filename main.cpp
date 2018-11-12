#include <iostream>
#include <fstream>
#include <string>

/*int fact(int n){
    if (n==0) {
        return 1;
    }
    else {
        return n*fact(n-1);
    }
}*/

// struct edge
// vector edges
// vector verteces
// build graph
// check graph: step 0
// build sorted edges
// check cycle
// return tree

#include "unionfind.h"

void einlesen() {
    std::ifstream file;
    std::string line;
    file.open("C:\\Instanz1.txt");
    if (file.is_open()){
        while(std::getline(file, line)){
            std::cout<<line<<std::endl;
        }
        file.close();
    }
    else {
        std::cerr<<"Fehler beim oeffnen der Datei!"<<std::endl;
    }
}

int main() {
    std::ifstream file;
    std::string line;
    file.open("C:\\Instanz1.txt");


/*
    if (file.is_open()){
        while(std::getline(file, line)){
            std::cout<<line<<std::endl;
        }
        file.close();
    }
    else {
        std::cerr<<"Fehler beim oeffnen der Datei!"<<std::endl;
    }*/
    unsigned vertex_count;
    file>>vertex_count;
    std::cout<<vertex_count<<std::endl;

    int n = 0;

    int a,b,weight;
    Graph *graph = new Graph;


    graph->edges.reserve(100);
    while (!file.eof()) {
        file>>a>>b>>weight;
        std::cout<<a<<" "<<b<<" "<<weight<<std::endl;
        Edge *edge = &graph->edges[n];
        edge->a=a;
        edge->b=b;
        edge->weight;
        n++;
    }

    for (unsigned i=0;i<=n;i++){
        std::cout<<graph->edges[i].a<<" "<<graph->edges[i].b<<" "<<graph->edges[i].weight<<std::endl;
    }

    return 0;
}
    /*std::vector<int> *partitions = {-1,-1,-1,-1};

   // initPartition()
   int test1 = find(1, partitions);
    // 1

   int test2 = find(2, partitions);
    // 2

   int test3 = find(3, partitions);
    // 2

    unify(2,3, partitions);

    int test4 = find(2, partitions);
    // 2

    int test5 = find(3, partitions);
    // 2

    // test 4 == test 5



    //3
    std::cout<<test1<<std::endl;
   if (test1 == 3 ) std::cout<<"ok"<<std::endl;
    int test2 = find(parents,0);
    //1
    std::cout<<test2<<std::endl;
    if (test2 == 1 ) std::cout<<"ok"<<std::endl;

}*/
/*
void einlesen() {
    std::ifstream file;
    std::string line;
    file.open("C:\\Instanz1.txt");
    if (file.is_open()){
        while(std::getline(file, line)){
            std::cout<<line<<std::endl;
        }
        file.close();
    }
    else {
        std::cerr<<"Fehler beim oeffnen der Datei!"<<std::endl;
    }
}
*/

// Schritt 1: Interpretation
// 1.Zeile lesen => Array mit Knoten erstellen von 0 bis n-1
// nach der 1.Zeile: immer die ersten beiden Zahlen als Kante interpretieren(?)
// Graphendurchmusterung: zhg oder nicht => Abbruch, falls nicht
// die dritte Zahl als Gewicht der passenden Kante zuordnen
// m:= Anzahl der Kanten
// m-dimensionales Array der Laenge 3 a[i,0], a[i,1] Kante, a[i,2] Kosten fuer i=0,...,m-1
// Alternative: Vector-Klasse??
// Schritt 2: Sortierung: Sortiere Kanten nach Gewicht mit qsort bzw std::sort
// Schritt 3: Union Find Kreise, Hinzufügen, Zhk verwalten
// Schritt 4: Ausgabe
#include <iostream>
#include <fstream>
#include <string>


// struct edge
// vector edges
// vector verteces
// build graph
// check graph: step 0
// build sorted edges
// check cycle
// return tree

int main() {
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
    return 0;
}
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
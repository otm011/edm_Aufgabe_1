//
// Created by Mo on 11.11.2018.
//

#include <vector>

#ifndef UNION_FIND_CYCLE_UNIONFIND_H_H
#define UNION_FIND_CYCLE_UNIONFIND_H_H

#endif //UNION_FIND_CYCLE_UNIONFIND_H_H

struct Edge {
    unsigned long a,b; // a!=b
    int weight;
};

struct Graph {
    unsigned vertex_count;
    unsigned edge_count;
    std::vector<Edge> edges;
};


void make_set(unsigned long vertex_count);

unsigned long find (unsigned long i);

void Union (unsigned long i, unsigned long j);

/*int find (int x, Graph *graph);
int parent (int x, Graph *graph);*/

/*gegeben: Ordnung der Kanten nach Kosten => gehe die Kanten nacheinander durch, entscheide in jedem Schritt,
ob der graph einen Kreis besitzt => was haben wir zu tun: in einem beliebigen Schritt entscheiden, ob der Graph einen
Kreis besitzt*/

/*int find(int x,std::vector<int> *partitions);

Graph path_compression (Graph *graph);

void initPartition(Graph *graph, std::vector<int> *partitions);

void make_set(int x);

void unify(int x, int y, std::vector<int> *partitions);
*/
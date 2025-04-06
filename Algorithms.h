//Email: adhamhamoudy3@gmail.com
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {

class Algorithms {
public:
    static Graph BFS(const Graph& g, int startVertex);
    static Graph DFS(const Graph& g, int startVertex);
    static Graph Dijkstra(const Graph& g, int startVertex);
    static Graph Prim(const Graph& g);
    static Graph Kruskal(const Graph& g);
};

}

#endif


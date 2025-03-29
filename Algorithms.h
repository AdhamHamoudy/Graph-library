#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {

class Algorithms {
public:
    // Traversal algorithms
    static void BFS(Graph& g, int startVertex);
    static void DFS(Graph& g, int startVertex);

    // Shortest path / MST algorithms
    static void Dijkstra(Graph& g, int startVertex);
    static void Prim(Graph& g);
    static void Kruskal(Graph& g);
};

} // namespace graph

#endif // ALGORITHMS_H

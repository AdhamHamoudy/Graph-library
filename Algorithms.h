#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {

class Algorithms {
public:
    // Traversal algorithms that return new graphs
    static Graph BFS(const Graph& g, int startVertex);
    static Graph DFS(const Graph& g, int startVertex);

    // Shortest path and MST algorithms
    static Graph Dijkstra(const Graph& g, int startVertex);
    static Graph Prim(const Graph& g);
    static Graph Kruskal(const Graph& g);
};

} // namespace graph

#endif // ALGORITHMS_H

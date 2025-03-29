#include <iostream>
#include "Graph.h"
#include "Algorithms.h"

using namespace std;
using namespace graph;

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges (undirected)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    // Print the graph
    cout << "Adjacency List of Graph:" << endl;
    g.print_graph();

    cout << "\n============================\n";
    Algorithms::BFS(g, 0);

    cout << "\n============================\n";
    Algorithms::DFS(g, 0);

    cout << "\n============================\n";
    Algorithms::Dijkstra(g, 0);

    cout << "\n============================\n";
    Algorithms::Prim(g);

    cout << "\n============================\n";
    Algorithms::Kruskal(g);

    return 0;
}
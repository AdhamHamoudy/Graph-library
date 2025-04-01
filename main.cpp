#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace std;
using namespace graph;

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    cout << "Adjacency List of Graph:\n";
    g.print_graph();

    cout << "\n============================\n";
    cout << "BFS starting from vertex 0:\n";
    Graph bfsTree = Algorithms::BFS(g, 0);
    bfsTree.print_graph();

    cout << "\n============================\n";
    cout << "DFS starting from vertex 0:\n";
    Graph dfsTree = Algorithms::DFS(g, 0);
    dfsTree.print_graph();

    cout << "\n============================\n";
    cout << "Dijkstra from vertex 0:\n";
    Graph dijkstraTree = Algorithms::Dijkstra(g, 0);
    dijkstraTree.print_graph();

    cout << "\n============================\n";
    cout << "Prim's MST:\n";
    Graph primMST = Algorithms::Prim(g);
    primMST.print_graph();

    cout << "\n============================\n";
    cout << "Kruskal's MST:\n";
    Graph kruskalMST = Algorithms::Kruskal(g);
    kruskalMST.print_graph();

    return 0;
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.h"
#include "Algorithms.h"

using namespace graph;

TEST_CASE("Test BFS") {
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

    Graph bfsTree = Algorithms::BFS(g, 0);
    CHECK(bfsTree.getNumVertices() == g.getNumVertices());
    bfsTree.print_graph();
}

TEST_CASE("Test DFS") {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    Graph dfsTree = Algorithms::DFS(g, 0);
    CHECK(dfsTree.getNumVertices() == g.getNumVertices());
    dfsTree.print_graph();
}

TEST_CASE("Test Dijkstra") {
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

    Graph shortestPaths = Algorithms::Dijkstra(g, 0);
    CHECK(shortestPaths.getNumVertices() == g.getNumVertices());
    shortestPaths.print_graph();
}

TEST_CASE("Test Prim") {
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

    Graph mst = Algorithms::Prim(g);
    CHECK(mst.getNumVertices() == g.getNumVertices());
    mst.print_graph();
}

TEST_CASE("Test Kruskal") {
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

    Graph mst = Algorithms::Kruskal(g);
    CHECK(mst.getNumVertices() == g.getNumVertices());
    mst.print_graph();
}

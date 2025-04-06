#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

namespace graph {

    struct Node {
        int vertex;
        int weight;
        Node* next;
    };

    class Graph {
    private:
        int numVertices;
        Node** adjList;

    public:
        Graph(int vertices);
        ~Graph();

        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph();

        int getNumVertices() const;
        Node** getAdjList() const;
    };

}

#endif 


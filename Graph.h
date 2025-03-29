#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

namespace graph {

    // Node for linked list in adjacency list
    struct Node {
        int vertex;
        int weight;
        Node* next;
    };

    class Graph {
    private:
        int numVertices;    // Total vertices in graph
        Node** adjList;     // Array of pointers to linked lists

    public:
        // Constructor and Destructor
        Graph(int vertices);
        ~Graph();

        // Basic operations
        void addEdge(int src, int dest, int weight = 1);
        void removeEdge(int src, int dest);
        void print_graph();

        // Getters (for use in Algorithms)
        int getNumVertices() const;
        Node** getAdjList() const;
    };

}

#endif // GRAPH_H

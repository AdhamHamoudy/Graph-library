#include "Graph.h"

using namespace std;
using namespace graph;


Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList = new Node*[numVertices];

    for (int i = 0; i < numVertices; i++) {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}

void Graph::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        throw std::out_of_range("addEdge: Invalid vertex index.");
    }
    if (src == dest) {
        throw std::invalid_argument("addEdge: Self-loops are not allowed.");
    }

    // Add edge in both directions (undirected)
    Node* newNode = new Node{dest, weight, adjList[src]};
    adjList[src] = newNode;

    newNode = new Node{src, weight, adjList[dest]};
    adjList[dest] = newNode;
}


bool removeHelper(Node*& head, int vertex) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->vertex == vertex) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        throw std::out_of_range("removeEdge: Invalid vertex index.");
    }
    
    bool removedSrc = removeHelper(adjList[src], dest);
    bool removedDest = removeHelper(adjList[dest], src);

    if (!removedSrc || !removedDest) {
        throw std::runtime_error("Edge does not exist.");
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

Node** Graph::getAdjList() const {
    return adjList;
}

void Graph::print_graph() {
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        Node* current = adjList[i];
        while (current != nullptr) {
            cout << "(" << current->vertex << ", weight: " << current->weight << ") ";
            current = current->next;
        }
        cout << endl;
    }
}


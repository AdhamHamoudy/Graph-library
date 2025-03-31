#include "Algorithms.h"
#include <iostream>
#include <climits>

using namespace std;
using namespace graph;

// =========================
// Helper Queue (for BFS)
// =========================
class IntQueue {
    int* data;
    int front, rear, size, capacity;
public:
    IntQueue(int cap) : front(0), rear(-1), size(0), capacity(cap) {
        data = new int[cap];
    }
    ~IntQueue() { delete[] data; }

    void enqueue(int val) {
        if (size == capacity) return;
        rear = (rear + 1) % capacity;
        data[rear] = val;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = data[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    bool isEmpty() const { return size == 0; }
};

// =========================
// BFS
// =========================
Graph Algorithms::BFS(const Graph& g, int startVertex) {
    int n = g.getNumVertices();
    bool* visited = new bool[n]{};
    IntQueue q(n);
    Graph bfsTree(n);

    visited[startVertex] = true;
    q.enqueue(startVertex);

    while (!q.isEmpty()) {
        int u = q.dequeue();
        Node* temp = g.getAdjList()[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = true;
                q.enqueue(v);
                bfsTree.addEdge(u, v, temp->weight);
            }
            temp = temp->next;
        }
    }

    delete[] visited;
    return bfsTree;
}

// =========================
// DFS
// =========================
void dfsUtil(const Graph& g, Graph& dfsTree, int v, bool* visited) {
    visited[v] = true;
    Node* temp = g.getAdjList()[v];
    while (temp != nullptr) {
        if (!visited[temp->vertex]) {
            dfsTree.addEdge(v, temp->vertex, temp->weight);
            dfsUtil(g, dfsTree, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

Graph Algorithms::DFS(const Graph& g, int startVertex) {
    int n = g.getNumVertices();
    bool* visited = new bool[n]{};
    Graph dfsTree(n);
    dfsUtil(g, dfsTree, startVertex, visited);
    delete[] visited;
    return dfsTree;
}

// =========================
// Dijkstra
// =========================
Graph Algorithms::Dijkstra(const Graph& g, int startVertex) {
    int n = g.getNumVertices();
    int* dist = new int[n];
    bool* visited = new bool[n]{};
    int* parent = new int[n];

    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[startVertex] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        Node* temp = g.getAdjList()[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    Graph tree(n);
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            Node* temp = g.getAdjList()[i];
            while (temp != nullptr) {
                if (temp->vertex == parent[i]) {
                    tree.addEdge(parent[i], i, temp->weight);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    delete[] dist;
    delete[] visited;
    delete[] parent;
    return tree;
}

// =========================
// Prim's Algorithm
// =========================
Graph Algorithms::Prim(const Graph& g) {
    int n = g.getNumVertices();
    bool* inMST = new bool[n]{};
    int* key = new int[n];
    int* parent = new int[n];

    for (int i = 0; i < n; ++i) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = -1, minKey = INT_MAX;
        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        inMST[u] = true;

        Node* temp = g.getAdjList()[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    Graph mst(n);
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            Node* temp = g.getAdjList()[i];
            while (temp != nullptr) {
                if (temp->vertex == parent[i]) {
                    mst.addEdge(parent[i], i, temp->weight);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    delete[] inMST;
    delete[] key;
    delete[] parent;
    return mst;
}

// =========================
// Kruskal's Algorithm
// =========================
struct Edge {
    int src, dest, weight;
};

int find(int* parent, int i) {
    while (parent[i] != i) i = parent[i];
    return i;
}

void unite(int* parent, int* rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

Graph Algorithms::Kruskal(const Graph& g) {
    int n = g.getNumVertices();
    Node** adj = g.getAdjList();

    int maxEdges = n * (n - 1) / 2;
    Edge* edges = new Edge[maxEdges];
    int edgeCount = 0;
    bool** added = new bool*[n];
    for (int i = 0; i < n; ++i) added[i] = new bool[n]{};

    for (int u = 0; u < n; ++u) {
        Node* temp = adj[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            if (!added[u][v] && !added[v][u]) {
                edges[edgeCount++] = { u, v, temp->weight };
                added[u][v] = added[v][u] = true;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = i + 1; j < edgeCount; ++j) {
            if (edges[j].weight < edges[i].weight) {
                Edge tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }

    int* parent = new int[n];
    int* rank = new int[n]{};
    for (int i = 0; i < n; ++i) parent[i] = i;

    Graph mst(n);
    int edgesUsed = 0;
    for (int i = 0; i < edgeCount && edgesUsed < n - 1; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            mst.addEdge(u, v, edges[i].weight);
            unite(parent, rank, setU, setV);
            edgesUsed++;
        }
    }

    for (int i = 0; i < n; ++i) delete[] added[i];
    delete[] added;
    delete[] edges;
    delete[] parent;
    delete[] rank;

    return mst;
}
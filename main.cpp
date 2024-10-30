#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// This class represents a directed graph using an adjacency list representation
class Graph {
    int V;                     // Number of vertices
    vector<list<int>> adj;     // Adjacency lists for each vertex

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Function to print BFS traversal from a given source vertex
    void BFS(int s);
};

// Initialize graph with a given number of vertices
Graph::Graph(int V) : V(V), adj(V) {}

// Add an edge to the graph (directed)
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);  // Add w to v’s adjacency list
}

// Perform BFS traversal from a given source vertex
void Graph::BFS(int s) {
    // Vector to track visited vertices
    vector<bool> visited(V, false);

    // Queue for BFS
    queue<int> q;

    // Mark the source vertex as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it as visited and enqueue it
        for (int adjVertex : adj[vertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
}

// Driver program to test methods of the Graph class
int main() {
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth-First Traversal (starting from vertex 2):\n";
    g.BFS(2);

    return 0;
}

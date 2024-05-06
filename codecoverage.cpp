#include <iostream>
#include <vector>
#include <limits.h>
#include <stdexcept>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    if (V <= 0) {
        cerr << "Error: Number of vertices must be greater than zero." << endl;
        return 1;
    }

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            // Ensure non-negative edge weights
            if (graph[i][j] < 0) {
                cerr << "Error: Edge weights must be non-negative." << endl;
                return 1;
            }
        }
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    if (src < 0 || src >= V) {
        cerr << "Error: Source vertex index is out of range." << endl;
        return 1;
    }

    dijkstra(graph, src);

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>  
using namespace std;

#define V 9  // Number of vertices in the graph

int minDistance(const vector<int>& dist, const vector<bool>& visited) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    
    return min_index;
}

// Function to print the shortest path from source to all vertices
void printSolution(const vector<int>& dist) {
    cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

// Dijkstra's single source shortest path algorithm for a graph
// represented using adjacency matrix
void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);  // The output array. dist[i] holds the shortest distance from src to i
    vector<bool> visited(V, false);  // visited[i] will be true if vertex i is included in shortest path tree
    
    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, visited);
        
        visited[u] = true;  // Mark the picked vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            // Update dist[v] only if it's not in visited, there's an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph, 0);  // 0 is the source node

    return 0;
}

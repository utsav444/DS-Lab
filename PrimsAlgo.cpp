#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(const vector<int> &key, const vector<bool> &mstSet, int V)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(const vector<int> &parent, const vector<vector<int>> &graph, int V)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primMST(const vector<vector<int>> &graph, int V)
{
    vector<int> parent(V);         // Stores the constructed MST
    vector<int> key(V, INT_MAX);   // Key values to pick minimum weight edge
    vector<bool> mstSet(V, false); // MST set to track vertices included in the MST

    key[0] = 0;     // Start from the first vertex
    parent[0] = -1; // First node is the root of MST

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main()
{
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph, V);

    return 0;
}

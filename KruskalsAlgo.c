#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph
#define E 7  // Number of edges in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find set of an element i (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets (uses union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to compare two edges by weight (used by qsort)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*) a;
    struct Edge* edgeB = (struct Edge*) b;
    return edgeA->weight > edgeB->weight;
}

// Kruskal's algorithm to find MST
void KruskalMST(struct Edge edges[]) {
    struct Edge result[V - 1];  // Store the resulting MST
    struct Subset subsets[V];   // Subsets for union-find

    // Initialize subsets
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Sort all the edges in non-decreasing order of weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int e = 0;  // Counter for result[]
    int i = 0;  // Counter for edges[]

    while (e < V - 1) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If adding this edge doesn't form a cycle, include it in the MST
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the resulting MST
    printf("Edge \tWeight\n");
    for (int i = 0; i < e; ++i)
        printf("%d -- %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    // Manually defined graph (edges with src, dest, and weight)
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    // Find MST using Kruskal's algorithm
    KruskalMST(edges);

    return 0;
}

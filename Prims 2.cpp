#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

struct Node {
    int value, key;
};

void swap(struct Node *x, struct Node *y) {
    struct Node temp = *x;
    *x = *y;
    *y = temp;
}

struct MinHeap {
    struct Node *array;
    int size;
    int capacity;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node*)malloc(capacity * sizeof(struct Node));
    return minHeap;
}

void minHeapify(struct MinHeap* minHeap, int index, int n) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && minHeap->array[left].key < minHeap->array[smallest].key) {
        smallest = left;
    }

    if (right < n && minHeap->array[right].key < minHeap->array[smallest].key) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&minHeap->array[index], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest, n);
    }
}

struct Node extractMin(struct MinHeap* minHeap) {
    struct Node minNode = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0, minHeap->size);
    return minNode;
}

void decreaseKey(struct MinHeap* minHeap, int v, int key) {
    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i].value == v) {
            break;
        }
    }
    minHeap->array[i].key = key;
    while (i != 0 && minHeap->array[(i - 1) / 2].key > minHeap->array[i].key) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap* minHeap, int v) {
    for (int i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i].value == v) {
            return true;
        }
    }
    return false;
}

void primMST(struct Edge** graph, int n, int start) {
    int* parent = (int*)malloc(n * sizeof(int));
    int* key = (int*)malloc(n * sizeof(int));
    bool* inMinHeap = (bool*)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        key[i] = INF;
        inMinHeap[i] = false;
    }

    struct MinHeap* minHeap = createMinHeap(n);
    key[start] = 0;
    minHeap->array[minHeap->size].value = start;
    minHeap->array[minHeap->size].key = key[start];
    minHeap->size++;

    while (minHeap->size > 0) {
        struct Node minNode = extractMin(minHeap);
        int u = minNode.value;
        inMinHeap[u] = false;

        for (int i = 0; i < n; i++) {
            if (isInMinHeap(minHeap, i) && graph[u][i].weight < key[i]) {
                key[i] = graph[u][i].weight;
                parent[i] = u;
                decreaseKey(minHeap, i, key[i]);
            }
        }
    }

    // Printing the minimum spanning tree
    for (int i = 1; i < n; i++) {
        printf("Edge: %d - %d Weight: %d\n", parent[i], i, key[i]);
    }

    free(parent);
    free(key);
    free(inMinHeap);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    int n, m; // Number of nodes and edges
    scanf("%d %d", &n, &m);

    struct Edge** graph = (struct Edge**)malloc(n * sizeof(struct Edge*));
    for (int i = 0; i < n; i++) {
        graph[i] = (struct Edge*)malloc(n * sizeof(struct Edge));
    }

    for (int i = 0; i < m; i++) {
        int u, v, w; // Edge from u to v with weight w
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].to = v;
        graph[u][v].weight = w;
        graph[v][u].to = u;
        graph[v][u].weight = w;
    }

    int start; // Starting node
    scanf("%d", &start);

    primMST(graph, n, start);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}


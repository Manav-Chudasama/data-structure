#include <stdio.h>
#define MAX 10

void breadth_first_search(int adj[][MAX], int visited[], int start, int numVertices)
{
    int queue[MAX], rear = -1, front = -1, i;

    // Enqueue the starting vertex
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (rear != front)
    {
        // Dequeue a vertex
        start = queue[++front];
        printf("%c\t", start + 65); // Convert vertex index to a character (A, B, C...)

        // Explore neighbors
        for (i = 0; i < numVertices; i++)
        {
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i; // Enqueue the neighbor
                visited[i] = 1;    // Mark as visited
            }
        }
    }
    printf("\n");
}

int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j, numVertices;

    // Input number of vertices
    printf("Enter the number of vertices (<= %d): ", MAX);
    scanf("%d", &numVertices);

    if (numVertices > MAX || numVertices <= 0)
    {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }

    // Input adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Perform BFS starting from vertex 0 (A)
    breadth_first_search(adj, visited, 0, numVertices);

    return 0;
}

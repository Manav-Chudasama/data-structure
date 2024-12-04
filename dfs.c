#include <stdio.h>
#define MAX 5

void depth_first_search(int adj[][MAX], int visited[], int start) {
    int stack[MAX];
    int top = -1, i;

    printf("%c-", start + 65); // Print the starting vertex
    visited[start] = 1;        // Mark the starting vertex as visited
    stack[++top] = start;      // Push the starting vertex onto the stack

    while (top != -1) {        // While the stack is not empty
        start = stack[top];
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) { // Found an unvisited adjacent vertex
                stack[++top] = i;                  // Push it onto the stack
                printf("%c-", i + 65);             // Print the vertex
                visited[i] = 1;                    // Mark as visited
                break;
            }
        }
        if (i == MAX)                              // If no unvisited adjacent vertex is found
            top--;                                 // Pop the stack (backtrack)
    }
}

int main() {
    int adj[MAX][MAX];
    int visited[MAX] = {0}, i, j;

    printf("\nEnter the adjacency matrix: ");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS Traversal: ");
    depth_first_search(adj, visited, 0);
    printf("\n");

    return 0;
}

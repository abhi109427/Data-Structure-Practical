
#include <stdio.h>

int graph[20][20], visited[20], n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start) {
    int queue[20], front = 0, rear = 0, i, v;
    
    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, edges, u, v, start, ch;

    printf("Enter number of vertices : ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid number of vertices!\n");
        return 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid vertex! Try again.\n");
            i--;
        } else {
            graph[u][v] = graph[v][u] = 1;
        }
    }

    do {
        printf("\n1. DFS Traversal");
        printf("\n2. BFS Traversal");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1 || ch == 2) {
            printf("Enter starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);

            if (start < 0 || start >= n) {
                printf("Invalid starting vertex!\n");
                continue;
            }

            for (i = 0; i < n; i++)
                visited[i] = 0;

            if (ch == 1) {
                printf("DFS: ");
                DFS(start);
            } else {
                printf("BFS: ");
                BFS(start);
            }
            printf("\n");
        } else if (ch == 3) {
            printf("Exit\n");
        } else {
            printf("Invalid choice!\n");
        }
    } while (ch != 3);

    return 0;
}

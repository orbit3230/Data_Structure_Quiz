#include <stdio.h>
#include <stdlib.h>

typedef struct GraphType {
    int n; // number of vertices
    int **adj_mat;
    int *visited;
} GraphType;

int left_max = 0;
int right_max = 0;

void init(GraphType* g, int n) {
    g->n = n;
    g->adj_mat = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        g->adj_mat[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            g->adj_mat[i][j] = 0;
        }
    }
    g->visited = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        g->visited[i] = 0;
    }
}

void insert_edge(GraphType* g, int start, int end, int weight) {
    g->adj_mat[start][end] = weight;
    g->adj_mat[end][start] = weight;
}

// 왼쪽으로 뻗어나갔을 때 가장 긴 거리를 찾는다.
void dfs_search_left(GraphType* g, int start, int visited[], int dist) {
    visited[start] = 1;
    for (int i = start+1; i < g->n; i++) {
        if (g->adj_mat[start][i] && !visited[i]) {
            int new_dist = dist + g->adj_mat[start][i];
            if (new_dist > left_max) {
                left_max = new_dist;
            }
            dfs_search_left(g, i, visited, new_dist);
        }
    }
    return;
}
// 오른쪽으로 뻗어나갔을 때 가장 긴 거리를 찾는다.
void dfs_search_right(GraphType* g, int start, int visited[], int dist) {
    visited[start] = 1;
    for (int i = start+1; i < g->n; i++) {
        if (g->adj_mat[start][i] && !visited[i]) {
            int new_dist = dist + g->adj_mat[start][i];
            if (new_dist > right_max) {
                right_max = new_dist;
            }
            dfs_search_right(g, i, visited, new_dist);
        }
    }
    return;
}


// 가장 거리가 먼 두 마을을 찾을 것이다.
// 가지를 왼쪽으로 뻗어나갔을 때의 가장 긴 거리와
// 오른쪽으로 뻗어나갔을 때의 가장 긴 거리를 더해서 반환한다.
void dfs_search(GraphType* g, int start, int visited[]) {
    int from = start+1;
    while((from < g->n) && !g->adj_mat[start][from]) {
        from++;
    }
    dfs_search_left(g, from, visited, g->adj_mat[start][from]);
    from++;
    while((from < g->n) && !g->adj_mat[start][from]) {
        from++;
    }
    dfs_search_right(g, from, visited, g->adj_mat[start][from]);

    return;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        GraphType g;

        int n;  // # of vertices
        scanf("%d", &n);
        init(&g, n);

        int u, v, d;  // u : uth vertex, v : vth vertex, d : distance
        for(int j = 0; j < n-1; j++) {
            scanf("%d %d %d", &u, &v, &d);
            u--; v--; // 0-based index
            insert_edge(&g, u, v, d);
        }

        int max = 0;
        int sumLR;
        for(int j = 0; j < n; j++) {
            // --- initialize ---
            left_max = 0;
            right_max = 0;
            for(int k = 0; k < n; k++) {
                g.visited[k] = 0;
            }
            // ------------------
            dfs_search(&g, j, g.visited);
            sumLR = left_max + right_max;
            if (sumLR > max) {
                max = sumLR;
            }
        }

        printf("%d\n", max);

        for (int j = 0; j < n; j++) {
            free(g.adj_mat[j]);
        }
        free(g.adj_mat);
        free(g.visited);
    }
}
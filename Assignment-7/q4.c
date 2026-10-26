#include <stdio.h>

int g[100][100], vis[100], n;

int dfs(int u, int parent) {
    vis[u] = 1;

    for (int v = 0; v < n; v++) {
        if (g[u][v]) {
            if (!vis[v]) {
                if (dfs(v, u)) return 1;
            } else if (v != parent)
                return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, -1)) {
            printf("Cycle exists");
            return 0;
        }

    printf("No cycle");
    return 0;
}

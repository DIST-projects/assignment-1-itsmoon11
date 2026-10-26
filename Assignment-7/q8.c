#include <stdio.h>
#include <string.h>

int g[100][100], vis[100], n;

void dfs(int u) {
    vis[u] = 1;
    for (int v = 0; v < n; v++)
        if (g[u][v] && !vis[v])
            dfs(v);
}

int main() {
    int i, candidate = -1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (i = 0; i < n; i++)
        if (!vis[i]) {
            dfs(i);
            candidate = i;
        }

    memset(vis, 0, sizeof(vis));
    dfs(candidate);

    for (i = 0; i < n; i++)
        if (!vis[i]) {
            printf("No mother vertex");
            return 0;
        }

    printf("Mother vertex = %d", candidate);
    return 0;
}

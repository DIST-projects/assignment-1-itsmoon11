#include <stdio.h>
#include <string.h>

int g[100][100], t[100][100], vis[100];
int st[100], top = -1, n;

void dfs1(int u) {
    vis[u] = 1;
    for (int v = 0; v < n; v++)
        if (g[u][v] && !vis[v]) dfs1(v);
    st[++top] = u;
}

void dfs2(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++)
        if (t[u][v] && !vis[v]) dfs2(v);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            t[j][i] = g[i][j];
        }

    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs1(i);

    memset(vis, 0, sizeof(vis));

    while (top >= 0) {
        int u = st[top--];
        if (!vis[u]) {
            printf("SCC: ");
            dfs2(u);
            printf("\n");
        }
    }

    return 0;
}

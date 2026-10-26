#include <stdio.h>

#define INF 999999

int g[100][100], d[100], vis[100], n;

int main() {
    int s, i, j, u;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    scanf("%d", &s);

    for (i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;

    for (i = 0; i < n; i++) {
        u = -1;
        for (j = 0; j < n; j++)
            if (!vis[j] && (u == -1 || d[j] < d[u]))
                u = j;

        if (u == -1 || d[u] == INF) break;
        vis[u] = 1;

        for (j = 0; j < n; j++)
            if (g[u][j] > 0 && !vis[j] &&
                d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }

    for (i = 0; i < n; i++)
        if (d[i] == INF) printf("%d: INF\n", i);
        else printf("%d: %d\n", i, d[i]);

    return 0;
}

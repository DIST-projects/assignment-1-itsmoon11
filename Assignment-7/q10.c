#include <stdio.h>

int g[100][100], color[100], n, q[100];

int main() {
    int i, j, s, u, v, f, r;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (i = 0; i < n; i++) color[i] = -1;

    for (s = 0; s < n; s++) {
        if (color[s] != -1) continue;

        f = r = 0;
        q[r++] = s;
        color[s] = 0;

        while (f < r) {
            u = q[f++];

            for (v = 0; v < n; v++) {
                if (!g[u][v]) continue;

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q[r++] = v;
                } else if (color[v] == color[u]) {
                    printf("Not Bipartite");
                    return 0;
                }
            }
        }
    }

    printf("Bipartite");
    return 0;
}

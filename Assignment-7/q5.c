#include <stdio.h>

char a[100][100];
int m, n;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y) {
    a[x][y] = 'W';

    for (int k = 0; k < 8; k++) {
        int u = x + dx[k], v = y + dy[k];

        if (u >= 0 && u < m && v >= 0 && v < n &&
            a[u][v] == 'L')
            dfs(u, v);
    }
}

int main() {
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &a[i][j]);

    int count = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'L') {
                count++;
                dfs(i, j);
            }

    printf("Number of islands = %d", count);
    return 0;
}

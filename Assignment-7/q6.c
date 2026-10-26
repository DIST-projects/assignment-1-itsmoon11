#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

Edge e[1000];
int p[100];

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m, i, count = 0, total = 0;
    scanf("%d%d", &n, &m);

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++) p[i] = i;
    qsort(e, m, sizeof(Edge), cmp);

    for (i = 0; i < m && count < n - 1; i++) {
        int a = find(e[i].u), b = find(e[i].v);

        if (a != b) {
            p[a] = b;
            printf("%d - %d : %d\n", e[i].u,
                   e[i].v, e[i].w);
            total += e[i].w;
            count++;
        }
    }

    if (count == n - 1)
        printf("MST cost = %d", total);
    else
        printf("MST does not exist");

    return 0;
}

#include <stdio.h>

int h[100], size = 0;

void insert(int x) {
    int i = size++;
    h[i] = x;

    while (i > 0 && h[(i - 1) / 2] < h[i]) {
        int t = h[i];
        h[i] = h[(i - 1) / 2];
        h[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

int deleteMax() {
    int x = h[0], i = 0;
    h[0] = h[--size];

    while (2 * i + 1 < size) {
        int c = 2 * i + 1;
        if (c + 1 < size && h[c + 1] > h[c])
            c++;
        if (h[i] >= h[c]) break;

        int t = h[i];
        h[i] = h[c];
        h[c] = t;
        i = c;
    }
    return x;
}

int main() {
    int n, x, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    for (i = 0; i < size; i++)
        printf("%d ", h[i]);

    if (size > 0)
        printf("\nMaximum = %d", deleteMax());

    return 0;
}

#include <stdio.h>
#define MAX 100

void insertFront(int a[], int *n, int x) {
    for (int i = *n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = x;
    (*n)++;
}

int searchAdjust(int a[], int n, int x) {
    int i, t;

    for (i = 0; i < n && a[i] != x; i++);

    if (i == n) return 0;

    t = a[i];
    for (int j = i; j > 0; j--)
        a[j] = a[j - 1];

    a[0] = t;
    return 1;
}

void show(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[MAX], n = 0;

    insertFront(a, &n, 10);
    insertFront(a, &n, 20);
    insertFront(a, &n, 30);
    insertFront(a, &n, 40);

    printf("Initial: ");
    show(a, n);

    searchAdjust(a, n, 20);

    printf("After search: ");
    show(a, n);
    return 0;
}

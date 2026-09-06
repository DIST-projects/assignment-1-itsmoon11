#include <stdio.h>

#define MAX 100

void frequency(int arr[], int n, int freq[]) {
    for (int i = 0; i < n; i++) {
        freq[i] = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                freq[i]++;
            }
        }
    }
}

void nextHigherFrequency(int arr[], int n, int result[]) {
    int freq[MAX];
    int stack[MAX];
    int top = -1;

    frequency(arr, n, freq);

    for (int i = n - 1; i >= 0; i--) {

        while (top != -1 &&
               freq[stack[top]] <= freq[i]) {
            top--;
        }

        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = arr[stack[top]];
        }

        stack[++top] = i;
    }
}

int main() {
    int arr[] = {2, 1, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[MAX];

    nextHigherFrequency(arr, n, result);

    printf("Input:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nOutput: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}

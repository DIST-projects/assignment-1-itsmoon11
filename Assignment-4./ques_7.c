#include <stdio.h>

#define MAX 20

void printMinimumNumber(char pattern[]) {
    int stack[MAX];
    int top = -1;
    int num = 1;

    for (int i = 0; pattern[i] != '\0'; i++) {

        stack[++top] = num++;

        if (pattern[i] == 'I') {
            while (top >= 0) {
                printf("%d", stack[top--]);
            }
        }
    }

    /* Push the final digit */
    stack[++top] = num++;

    while (top >= 0) {
        printf("%d", stack[top--]);
    }

    printf("\n");
}

int main() {
    char pattern1[] = "D";
    char pattern2[] = "DIDI";

    printf("Pattern: %s\n", pattern1);
    printf("Minimum number: ");
    printMinimumNumber(pattern1);

    printf("\nPattern: %s\n", pattern2);
    printf("Minimum number: ");
    printMinimumNumber(pattern2);

    return 0;
}

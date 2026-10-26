#include <stdio.h>
#define MAX 10
int a[MAX],t1=-1,t2=MAX;

void push1(int x) {
    if(t1+1==t2) printf("Full\n");
    else a[++t1]=x;
}
void push2(int x) {
    if(t1+1==t2) printf("Full\n");
    else a[--t2]=x;
}
void show() {
    printf("S1: ");
    for(int i=t1;i>=0;i--) printf("%d ",a[i]);
    printf("\nS2: ");
    for(int i=t2;i<MAX;i++) printf("%d ",a[i]);
    printf("\nArray: ");
    for(int i=0;i<MAX;i++) {
        if(i<=t1 || i>=t2) printf("%d ",a[i]);
        else printf("- ");
    }
    printf("\n");
}
int main() {
    push1(10); push1(20); push1(30);
    push2(90); push2(80); push2(70);
    show();
    return 0;
}

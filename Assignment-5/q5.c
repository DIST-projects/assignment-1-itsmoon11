#include <stdio.h>
#include <stdlib.h>
typedef struct N { int d; struct N *next; } N;

void append(N **h,int x) {
    N *p=malloc(sizeof(N)),*t;
    p->d=x; p->next=NULL;
    if(!*h) { *h=p; return; }
    t=*h; while(t->next) t=t->next;
    t->next=p;
}
void insert(N **h,int x,int pos) {
    N *p=malloc(sizeof(N)),*t=*h;
    p->d=x;
    if(pos==1) { p->next=*h; *h=p; return; }
    for(int i=1;i<pos-1;i++) t=t->next;
    p->next=t->next; t->next=p;
}
void show(N *h) {
    while(h) { printf("%d ",h->d); h=h->next; }
    printf("\n");
}
int main() {
    N *h=NULL; int n,x,v;
    scanf("%d",&n);
    for(int i=0;i<n;i++) { scanf("%d",&v); append(&h,v); }
    scanf("%d",&x);
    insert(&h,x,3);
    h->next->next->d=h->d;
    show(h);
    return 0;
}

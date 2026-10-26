#include <stdio.h>
#include <stdlib.h>
typedef struct N { int d; struct N *next; } N;

void insert(N **h,int x,int pos) {
    N *p=malloc(sizeof(N)),*t;
    int len=0;
    if(*h) {
        t=*h;
        do { len++; t=t->next; } while(t!=*h);
    }
    if(pos<1 || pos>len+1) { free(p); return; }
    p->d=x;
    if(pos==1) {
        if(!*h) { *h=p; p->next=p; return; }
        t=*h;
        while(t->next!=*h) t=t->next;
        p->next=*h; t->next=p; *h=p;
    } else {
        t=*h;
        for(int i=1;i<pos-1;i++) t=t->next;
        p->next=t->next; t->next=p;
    }
}
void show(N *h) {
    if(!h) return;
    N *t=h;
    do { printf("%d ",t->d); t=t->next; } while(t!=h);
    printf("\n");
}
int main() {
    N *h=NULL; int n,x,pos,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) { scanf("%d",&v); insert(&h,v,i); }
    scanf("%d%d",&x,&pos);
    insert(&h,x,pos);
    show(h);
    return 0;
}

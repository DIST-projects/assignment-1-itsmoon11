#include <stdio.h>
#include <stdlib.h>
typedef struct N { int d; struct N *next; } N;

void insert(N **h,int x) {
    N *p=malloc(sizeof(N)),*t;
    p->d=x;
    if(!*h) { *h=p; p->next=p; return; }
    t=*h;
    while(t->next!=*h) t=t->next;
    t->next=p; p->next=*h;
}
N *previous(N *h,int x) {
    if(!h) return NULL;
    N *p=h,*c=h->next;
    while(c!=h) {
        if(c->d==x) return p;
        p=c; c=c->next;
    }
    return h->d==x ? p : NULL;
}
int main() {
    N *h=NULL,*p; int n,x,v;
    scanf("%d",&n);
    while(n--) { scanf("%d",&v); insert(&h,v); }
    scanf("%d",&x);
    p=previous(h,x);
    if(p) printf("Previous = %d\n",p->d);
    else printf("Not found\n");
    return 0;
}

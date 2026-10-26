

#include <stdio.h>
#include <stdlib.h>
typedef struct N { int d; struct N *next,*bottom; } N;

N *node(int x) {
    N *p=malloc(sizeof(N));
    p->d=x; p->next=p->bottom=NULL;
    return p;
}
void bottom(N *h,int x) {
    while(h->bottom) h=h->bottom;
    h->bottom=node(x);
}
N *merge(N *a,N *b) {
    if(!a) return b;
    if(!b) return a;
    if(a->d<=b->d) {
        a->bottom=merge(a->bottom,b);
        return a;
    }
    b->bottom=merge(a,b->bottom);
    return b;
}
N *flatten(N *h) {
    if(!h || !h->next) return h;
    h->next=flatten(h->next);
    return merge(h,h->next);
}
void show(N *h) {
    while(h) { printf("%d ",h->d); h=h->bottom; }
    printf("\n");
}
int main() {
    N *a=node(5),*b=node(10),*c=node(19),*d=node(28);
    a->next=b; b->next=c; c->next=d;
    bottom(a,7); bottom(a,8);
    bottom(b,20); bottom(c,22);
    bottom(d,40); bottom(d,45);
    show(flatten(a));
    return 0;
}

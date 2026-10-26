#include <stdio.h>
#include <stdlib.h>
typedef struct N { int c,e; struct N *next; } N;

void addTerm(N **h,int c,int e) {
    N *p=malloc(sizeof(N)), *t=*h;
    p->c=c; p->e=e; p->next=NULL;
    if(!*h) { *h=p; return; }
    while(t->next) t=t->next;
    t->next=p;
}
N *readPoly() {
    N *h=NULL; int n,c,e;
    scanf("%d",&n);
    while(n--) { scanf("%d%d",&c,&e); addTerm(&h,c,e); }
    return h;
}
N *add(N *a,N *b) {
    N *r=NULL;
    while(a && b) {
        if(a->e==b->e) {
            if(a->c+b->c) addTerm(&r,a->c+b->c,a->e);
            a=a->next; b=b->next;
        } else if(a->e>b->e) {
            addTerm(&r,a->c,a->e); a=a->next;
        } else {
            addTerm(&r,b->c,b->e); b=b->next;
        }
    }
    while(a) { addTerm(&r,a->c,a->e); a=a->next; }
    while(b) { addTerm(&r,b->c,b->e); b=b->next; }
    return r;
}
N *scale(N *a,int k) {
    N *r=NULL;
    while(a) { if(a->c*k) addTerm(&r,a->c*k,a->e); a=a->next; }
    return r;
}
void show(N *p) {
    if(!p) { printf("0"); return; }
    while(p) {
        printf("%dx^%d",p->c,p->e);
        if(p->next) printf(" + ");
        p=p->next;
    }
    printf("\n");
}
int main() {
    N *a,*b,*s,*m; int k;
    printf("P1 terms (n, coefficient exponent): ");
    a=readPoly();
    printf("P2 terms (n, coefficient exponent): ");
    b=readPoly();
    s=add(a,b);
    printf("Sum: "); show(s);
    printf("Scalar: "); scanf("%d",&k);
    m=scale(a,k);
    printf("Scaled P1: "); show(m);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct N { int d; struct N *next; } N;

N *append(N *h,int x) {
    N *p=malloc(sizeof(N)),*t;
    p->d=x; p->next=NULL;
    if(!h) return p;
    t=h; while(t->next) t=t->next;
    t->next=p; return h;
}
N *merge(N *a,N *b) {
    N dummy={0,NULL},*t=&dummy;
    while(a && b) {
        if(a->d<=b->d) { t->next=a; a=a->next; }
        else { t->next=b; b=b->next; }
        t=t->next;
    }
    t->next=a?a:b;
    return dummy.next;
}
N *mergeK(N *v[],int l,int r) {
    if(l>r) return NULL;
    if(l==r) return v[l];
    int m=(l+r)/2;
    return merge(mergeK(v,l,m),mergeK(v,m+1,r));
}
int main() {
    N *v[10],*r; int k,n,x;
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        v[i]=NULL; scanf("%d",&n);
        while(n--) { scanf("%d",&x); v[i]=append(v[i],x); }
    }
    r=mergeK(v,0,k-1);
    while(r) { printf("%d ",r->d); r=r->next; }
    printf("\n");
    return 0;
}

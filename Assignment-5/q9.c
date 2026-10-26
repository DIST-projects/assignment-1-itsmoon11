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
N *swapK(N *h,int k,int n) {
    if(k<1 || k>n) return h;
    int j=n-k+1;
    if(k==j) return h;
    if(k>j) { int z=k; k=j; j=z; }

    N dummy={0,h},*px=&dummy,*x=h,*py=&dummy,*y=h;
    for(int i=1;i<k;i++) { px=x; x=x->next; }
    for(int i=1;i<j;i++) { py=y; y=y->next; }

    if(x->next==y) {
        px->next=y; x->next=y->next; y->next=x;
    } else {
        px->next=y; py->next=x;
        N *t=x->next; x->next=y->next; y->next=t;
    }
    return dummy.next;
}
int main() {
    N *h=NULL; int n,k,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++) { scanf("%d",&x); h=append(h,x); }
    scanf("%d",&k);
    h=swapK(h,k,n);
    while(h) { printf("%d ",h->d); h=h->next; }
    printf("\n");
    return 0;
}

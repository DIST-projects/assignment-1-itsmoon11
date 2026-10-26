#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct N { int d; struct N *next; } N;

N *append(N *h,int x) {
    N *p=malloc(sizeof(N)),*t;
    p->d=x; p->next=NULL;
    if(!h) return p;
    t=h; while(t->next) t=t->next;
    t->next=p; return h;
}
N *make(char s[]) {
    N *h=NULL;
    for(int i=0;s[i];i++) h=append(h,s[i]-'0');
    return h;
}
void toArray(N *p,int a[]) {
    int i=0;
    while(p) { a[i++]=p->d; p=p->next; }
}
int main() {
    char s[100],t[100];
    int a[100],b[100],r[201]={0},i,j;
    scanf("%99s%99s",s,t);
    int n=strlen(s),m=strlen(t);
    N *x=make(s),*y=make(t),*ans=NULL;
    toArray(x,a); toArray(y,b);

    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            r[i+j+1]+=a[i]*b[j];

    for(i=n+m-1;i>0;i--) {
        r[i-1]+=r[i]/10;
        r[i]%=10;
    }
    i=0;
    while(i<n+m-1 && r[i]==0) i++;
    for(;i<n+m;i++) ans=append(ans,r[i]);

    while(ans) { printf("%d",ans->d); ans=ans->next; }
    printf("\n");
    return 0;
}

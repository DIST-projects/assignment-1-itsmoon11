#include <stdio.h>
int main() {
    int q[100],n,x,mx=0,sec=0,hm=0,hs=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    for(int i=0;i<n;i++) {
        x=q[i];
        if(!hm || x>mx) {
            if(hm) { sec=mx; hs=1; }
            mx=x; hm=1;
        } else if(x<mx && (!hs || x>sec)) {
            sec=x; hs=1;
        }
    }
    if(hs) printf("Second largest = %d\n",sec);
    else printf("Not found\n");
    return 0;
}

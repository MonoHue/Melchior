#include<bits/stdc++.h>
using namespace std;
int read() {
    char c=getchar(); int x=0,f=1;
    while (c<'0' || c>'9') {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0' && c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void print(int x) {
    if (x==0) return;
    printf("%d", x%2);
    print(x/2);
}
int main() {
    int T=read();
    while (T--) {
        int n=read();
        for (int k=1; k<=n+2; k++) {
            for (int i=0; i<(1<<k); i++) {
                int s=0;
                for (int j=0; j<k; j++) {
                    if ((i>>j)&1) s+=(j+1)*(j+1);
                    else s-=(j+1)*(j+1);
                }
                if (s==n) {
                    printf("%daa\n", k);
                    print(i); printf("\n");
                }
            }
        }
    }
    return 0;
}
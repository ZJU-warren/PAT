#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 2200
#define EXP 1e-9

double a[MAXN],b[MAXN],r[MAXN];
void Scan(int K,double p[]){
    int id;
    Fin(i,1,K){
        SfI(id);
        SfD(p[id]);
    }
}
bool Equ0(double x){
    return fabs(x) < EXP;
}
void Cal(){
    Fin(i,0,MAXN-1)
        r[i] = 0.0;
    Fin(i,0,MAXN-1) if(!Equ0(a[i])){
        Fin(j,0,MAXN-1) if(!Equ0(b[j]))
            r[i+j] += a[i] * b[j];
    }
}
void Print(){
    int cnt = 0;
    Fde(i,MAXN-1,0) if(!Equ0(r[i])){
        ++cnt;
    }
    printf("%d",cnt); /// error !! watch out the Specification!
    Fde(i,MAXN-1,0) if(!Equ0(r[i])){
        printf(" %d %.1lf",i,r[i]);
    }
    putchar('\n');
}
int main()
{
    int K;
    while(~SfI(K)){
        Scan(K,a);
        SfI(K);
        Scan(K,b);
        Cal();
        Print();
    }
    return 0;
}

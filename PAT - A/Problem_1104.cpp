#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 120000

double arr[MAXN];
int main()
{
    int N;
    while(~SfI(N)){
        Fin(i,0,N-1)
            SfD(arr[i]);
        double tot = 0;
        Fin(i,0,N-1)
            tot += ((LL)(i+1)*(N-i))*arr[i];
        printf("%.2lf\n",tot);//
    }
    return 0;
}

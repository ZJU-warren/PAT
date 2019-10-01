#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

#define MAXN 20000

double arr[MAXN];
int main()
{
    int N;
    while(~SfI(N)){
        Fin(i,0,N-1)
            SfD(arr[i]);
        sort(arr,arr+N);
        double ans = (arr[0] + arr[1]) / 2;
        Fin(i,2,N-1)
            ans = (ans + arr[i]) / 2;
        cout << (LL)ans << endl;
    }
    return 0;
}

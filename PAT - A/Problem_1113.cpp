#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfLL(x) scanf("%lld",&x)

typedef long long LL;

#define MAXN 105000
LL arr[MAXN],sum,sumMin;
int main()
{
    int N;
    while(~SfI(N)){
        sumMin = sum = 0;
        Fin(i,1,N){
            SfLL(arr[i]);
            sum += arr[i];
        }
        sort(arr+1,arr+N+1);
        Fin(i,1,N/2)
            sumMin += arr[i];
        printf("%d %lld\n",(N-N/2)-N/2,sum - 2*sumMin);
    }
    return 0;
}

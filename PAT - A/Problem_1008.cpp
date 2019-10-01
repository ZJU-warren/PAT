#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 1200

int req[MAXN];
int main()
{
    int N;
    while(~SfI(N)){
        Fin(i,1,N)
            SfI(req[i]);
        req[0] = 0;
        int sum = 0;
        Fin(i,1,N){
            if(req[i] <= req[i-1])
                sum += 4 * (req[i-1] - req[i]);
            else
                sum += 6 * (req[i] - req[i-1]);
            sum += 5;
        }
        printf("%d\n",sum);
    }
    return 0;
}

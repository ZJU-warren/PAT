#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 10

set<int> S;
set<int> :: iterator it;

char s[MAXN];
int Sum(){
    int res = 0;
    for(int i=0;s[i];++i)
        res += (s[i] - '0');
    return res;
}
int main()
{
    int N;
    while(~SfI(N)){
        S.clear();
        Fin(i,1,N){
            SfS(s);
            S.insert(Sum());
        }
        printf("%d\n",S.size());
        it = S.begin();
        if(it != S.end())
            printf("%d",*(it));
        for(++it; it != S.end(); ++it)
            printf(" %d",*(it));
        putchar('\n');
    }
    return 0;
}

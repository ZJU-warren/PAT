#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 1200

set<int> existRow,existD1,existD2;
int N,loc[MAXN];

bool Judge(){
    existRow.clear();
    existD1.clear();
    existD2.clear();
    Fin(i,1,N){
        if(existRow.find(loc[i]) != existRow.end())
            return false;
        else existRow.insert(loc[i]);
        if(existD1.find(loc[i] + i) != existD1.end())
            return false;
        else existD1.insert(loc[i] + i);
        if(existD2.find(loc[i] - i) != existD2.end())
            return false;
        else existD2.insert(loc[i] - i);
    }
    return true;
}
int main()
{
    int T;
    SfI(T);
    Fin(t,1,T){
        SfI(N);
        Fin(i,1,N)
            SfI(loc[i]);
        printf("%s\n",Judge()?"YES":"NO");
    }
    return 0;
}

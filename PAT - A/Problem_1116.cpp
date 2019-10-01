#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

typedef long long LL;
#define MAXN 15000

bool prime[MAXN];
void Seive(){
    memset(prime,false,sizeof prime);
    prime[0] = prime[1] = true;
    Fin(i,2,MAXN-1) if(!prime[i])
        for(LL j = (LL)i * i; j < MAXN; j += i)
            prime[j] = true;
}

map<int,int> M;
set<int> S;
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    //freopen("e:\\tsst.txt","w",stdout);
    Seive();
    int N,K,temp;
    while(~SfI(N)){
        M.clear();
        S.clear();
        Fin(i,1,N){
            SfI(temp);
             M[temp] = i;
        }
        SfI(K);
        Fin(i,1,K){
            SfI(temp);
            if(!M[temp]) /// look the sample output
                printf("%04d: Are you kidding?\n",temp);
            else if(S.find(temp) != S.end())
                printf("%04d: Checked\n",temp);
            else if(M[temp] == 1)
                printf("%04d: Mystery Award\n",temp);
            else if(!prime[M[temp]])
                printf("%04d: Minion\n",temp);
            else if(prime[M[temp]])
                printf("%04d: Chocolate\n",temp);
            S.insert(temp);
        }
    }

    return 0;
}

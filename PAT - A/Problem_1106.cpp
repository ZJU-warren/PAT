#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 120000

struct Obj{
    int far,deep,deg;
}node[MAXN];

int N;
double price,inc;

void Scan(int id){
    SfI(node[id].deg);
    node[id].deep = -1;
    int jd;
    Fin(i,1,node[id].deg){
        SfI(jd);
        node[jd].far = id;
    }
}

int Dfs(int id){
    //printf("%d\n",id);
    if(!(~id))
        return -1;
    if(~node[id].deep)
        return node[id].deep;
    return node[id].deep = 1 + Dfs(node[id].far);
}

double Cal(double a,int x){
    double ans = 1.0;
    while(x){
        if(x&1)
            ans *= a;
        a *= a;
        x >>= 1;
    }
    return ans;
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    while(~scanf("%d %lf %lf",&N,&price,&inc)){
        Fin(i,0,N-1)
            Scan(i);
        node[0].far = -1;
        int minDeep = INT_MAX,cnt = 0,deep;
        Fin(i,0,N-1) if(!node[i].deg){
            deep = Dfs(i);
            if(minDeep > deep){
                cnt = 1;
                minDeep = deep;
            }
            else if(minDeep == deep)
                ++cnt;
        }
        printf("%.4lf %d\n",price * Cal(1+inc*0.01,minDeep),cnt);
    }
    return 0;
}

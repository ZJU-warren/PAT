#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 100000 /// 5-digits : MAX = 99999

int arr[MAXN],que[MAXN];
bool exist[MAXN];
int main(){
    int N,K,f,t,temp;
    while(~SfI(N)){
        memset(arr,0xff,sizeof arr);
        memset(exist,false,sizeof exist);
        Fin(i,1,N){
            scanf("%d %d",&f,&t);
            arr[f] = t;
            arr[t] = f;
        }
        SfI(K);
        int Limit = -1,cnt = 0;
        Fin(i,1,K){
            SfI(temp);
            exist[temp] = true;
            Limit = max(Limit,temp);
        }
        Fin(i,1,Limit) if(exist[i] && (!(~arr[i]) || !exist[arr[i]])){
            que[cnt++] = i;
        }
        printf("%d\n",cnt);
        Fin(i,0,cnt-1)
            printf("%05d%c",que[i],i!=cnt-1?' ':'\n');
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 50200


int times[MAXN],cnt,x,K,N;
struct Obj{
    int v,n;
    Obj(){}
    Obj(int v,int n):v(v),n(n){}
}arr[15];

void Rec(){
    int limit = min(cnt,K);
    Fin(i,1,limit)
        printf(" %d",arr[i].v);
    putchar('\n');
}
void Add(){
    Obj e(x,++times[x]);
    int i,limit = min(cnt,K);
    for(i = 1; i <= limit && arr[i].v != e.v; ++i);
    arr[i] = e; // renew
    //printf("i,v,n  = %d %d %d\n",i,e.v,e.n);
    for(; i > 1; --i){
        if(arr[i-1].n < e.n || (arr[i-1].n == e.n && arr[i-1].v > e.v))
            arr[i] = arr[i-1];
        else
            break;
    }
    cnt += times[x] == 1; /** in the loop old cnt be used **/
    arr[i] = e;
}
int main(){
    //freopen("e:\\test.txt","r",stdin);
    while(~scanf("%d %d",&N,&K)){
        memset(times,0,sizeof times);
        SfI(x);
        cnt = 1;
        arr[cnt] = Obj(x,++times[x]);
        Fin(i,2,N){
            SfI(x);
            printf("%d:",x);
            Rec();
            Add();
        }
    }
    return 0;
}

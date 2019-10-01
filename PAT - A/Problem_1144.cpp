#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)

#define MAXN 100050

bool num[MAXN]={};
int main()
{
    int N,x;
    while(~SfI(N)){
        memset(num,false,sizeof num);
        Fin(i,1,N){
            SfI(x);
            if(x >= 1 && x <= N)
                num[x] = true;
        }
        Fin(i,1,N+1) if(!num[i]){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}

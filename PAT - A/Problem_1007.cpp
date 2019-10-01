#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 12000

int arr[MAXN],K;
bool Scan(){
    bool flag = false;
    Fin(i,1,K){
        SfI(arr[i]);
        if(arr[i] >= 0)
            flag = true;
    }
    return flag;
}

//! dp[i] = max{dp[i-1]+arr[i],arr[i]}
int dp[MAXN],s[MAXN],t[MAXN];
void Dp(){
    dp[0] = -0x3f3f3f3f;
    Fin(i,1,K){
        if(dp[i-1] >= 0){
            dp[i] = dp[i-1] + arr[i];
            s[i] = s[i-1];
            t[i] = i;
        }
        else{
            dp[i] = arr[i];
            s[i] = t[i] = i;
        }
    }
    int MaxV = -1,id;
    Fin(i,1,K) if(MaxV < dp[i]){
        MaxV = dp[i];
        id = i;
    }
    printf("%d %d %d\n",dp[id],arr[s[id]],arr[t[id]]);
}
int main()
{
    while(~SfI(K)){
        if(!Scan()){
            printf("0 %d %d\n",arr[1],arr[K]);
            continue;
        }
        Dp();
    }
    return 0;
}

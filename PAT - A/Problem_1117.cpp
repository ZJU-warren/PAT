#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 120000

/// binSearch lowerBound upBound!!!!!!
/// in the test just for is well in time
int arr[MAXN],N;
int UpLimitSearch(){
    int lef = 1, rig = N+1;
    while(lef < rig){
        int mid = (lef + rig) / 2;
        if(mid < arr[N - mid + 1])
            lef = mid + 1;
        else
            rig = mid;
        //printf("[%d,%d)\n",lef,rig);
    }
    return rig - 1;
}

/*int UpLimitSearch(){
    for(int i = 1; i <= N ; ++i){
        if(i >= arr[N - i + 1])
            return i - 1;
    }
    return N;
}*/
/// 9 9 9 9 9 9 9 9 9 10
int main(){
    while(~SfI(N)){
        memset(arr,0,sizeof arr); /// init
        Fin(i,1,N)
            SfI(arr[i]);
        sort(arr+1,arr+N+1);
        printf("%d\n",UpLimitSearch());
    }
    return 0;
}


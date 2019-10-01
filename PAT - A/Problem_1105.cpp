#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAX_MAT 126
#define MAXN 62550

int mat[MAX_MAT][MAX_MAT], arr[MAXN];

int n,m,N;

void Divide(int N){
    n = (int)(sqrt(N + 0.5));
    m = N / n;
    do{
        m = N / n;
    }while(N%n && --n);
}
bool MyCmp(const int& a,const int& b){
    return a > b;
}
/*void Set(int id){
    int x,y;

}*/


bool exist[MAX_MAT][MAX_MAT];
int x,y,cor;
/** cor : 0/1/2/3 R/D/L/U **/
void Next(){
    switch(cor){
    case 0:
        if(!exist[x][y+1])
            ++y;
        else
            cor = 1,++x;
        break;
    case 1:
        if(!exist[x+1][y])
            ++x;
        else
            cor = 2,--y;
        break;
    case 2:
        if(!exist[x][y-1])
            --y;
        else
            cor = 3,--x;
        break;
    case 3:
        if(!exist[x-1][y])
            --x;
        else
            cor = 0,++y;
        break;
    }
    exist[x][y] = true;
}

int main()
{
    while(~SfI(N)){
        Divide(N);
        Fin(i,0,N-1)
            SfI(arr[i]);
        sort(arr,arr+N,MyCmp);
        /*Fin(i,0,N-1)
            Set(i);*/
        //printf("%d %d\n",n,m);
        memset(exist,false,sizeof exist);
        Fin(i,0,m+1)
            exist[i][n+1] = exist[i][0] = true;
        Fin(i,0,n+1)
            exist[m+1][i] = exist[0][i] = true;
        x = 1;
        y = 0;
        cor = 0;
        Fin(i,0,N-1){
            Next();
            mat[x][y] = arr[i];
        }
        Fin(i,1,m)
            Fin(j,1,n)
                printf("%d%c",mat[i][j],j!=n?' ':'\n');
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)

typedef long long LL;

#define MAXN 500000

int len;
int a[MAXN],b[MAXN];
void Cal(){

    int cnt = 0;
    //printf("_len = %d__\n",len);
    for(int i = 0; i < len;){
        int num = 1;
        b[cnt++] = a[i];
        while(i < len && a[i] == a[i+1])
            ++i, ++num;
        b[cnt++] = num;
        ++i;
    }
    for(int i = 0; i < cnt; ++i)
        a[i] = b[i];
    len = cnt;
}
int D,n;
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    //freopen("e:\\tsst.txt","w",stdout);

    while(~scanf("%d %d",&D,&n)){
        a[0] = D;
        len = 1;
        Fin(i,2,n){
            Cal();
        }
        Fin(i,0,len-1)
            printf("%d",a[i]);
        putchar('\n');
        //printf("_len = %d__\n",len);
    }
    return 0;
}

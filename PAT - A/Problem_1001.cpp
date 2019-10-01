#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 1200

int a,b;
char str[20];
void Cal(){
    sprintf(str,"%d",a+b);
    int len = strlen(str), beg = 0;
    if(str[beg] =='-')
        printf("%c",str[beg++]),--len;
    int r = len % 3;
    Fin(i,1,r)
        printf("%c",str[beg++]);
    Fin(i,r+1,len){
        if((len-i+1)%3 == 0 && i != 1)
            putchar(',');
        printf("%c",str[beg++]);
    }
    putchar('\n');
}
int main()
{
    while(~scanf("%d %d",&a,&b)){
        Cal();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 120

char str[MAXN];
void Cal(){
    int len = strlen(str),res = 0;
    Fin(i,0,len-1)
        res += (str[i] - '0');
    memset(str,0,sizeof str);
    sprintf(str,"%d",res);
}

char num[][10] = {"zero","one","two","three",
    "four","five","six","seven","eight","nine"};

void Display(){
    int len = strlen(str);
    printf("%s",num[str[0] - '0']);
    Fin(i,1,len-1)
        printf(" %s",num[str[i] - '0']);
    putchar('\n');
}
int main()
{
    while(~scanf("%s",str)){
        Cal();
        Display();
    }
    return 0;
}

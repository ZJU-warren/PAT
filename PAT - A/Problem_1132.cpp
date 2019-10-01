#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

#define MAXN 200
char strA[MAXN],strB[MAXN],str[MAXN],None[MAXN];
LL a,b,z;
int main()
{
    int T;
    SfI(T);
    gets(None); ///
    Fin(t,1,T){
        SfS(str);
        int len = strlen(str);
        strncpy(strA,str,len/2);
        strncpy(strB,str+len/2,len/2);
        strA[len/2] = strB[len/2] = 0;
        sscanf(str,"%lld",&z);
        sscanf(strA,"%lld",&a);
        sscanf(strB,"%lld",&b);
        //printf("%lld %lld %lld\n",z,a,b);
        printf("%s\n",(a*b) && !(z%(a*b))?"Yes":"No");
    }
    return 0;
}

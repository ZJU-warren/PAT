#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 120
const double MIN_VALUE = -1000.0 - (1e-5);
const double MAX_VALUE = 1000.0 + (1e-5);

double tot,x;
char strX[MAXN];
inline int LegalLetter(char c){
    return '0' <= c && c <= '9';
}
bool Judge(){
    int len = strlen(strX),cntPoint = 0,afterPoint = 0;
    int beg = strX[0] == '-'? 1 : 0;
    Fin(i,beg,len-1){
        if(cntPoint)
            ++afterPoint;
        if(strX[i] == '.')
            ++cntPoint;
        else if(!LegalLetter(strX[i]))
            return false;
    }
    if(cntPoint > 1 || afterPoint > 2)
        return false;
    sscanf(strX,"%lf",&x);
    return MIN_VALUE < x && x < MAX_VALUE;
}
int main()
{
    int N,cnt;
    while(~SfI(N)){
        tot = cnt = 0;
        Fin(i,1,N){
            SfS(strX);
            if(Judge())
                tot += x, ++cnt;
            else
                printf("ERROR: %s is not a legal number\n",strX);
        }
        if(cnt)
            printf("The average of %d %s is %.2lf\n",cnt,cnt!=1?"numbers":"number",tot/cnt);
        else
            printf("The average of 0 numbers is Undefined\n");

    }
    return 0;
}

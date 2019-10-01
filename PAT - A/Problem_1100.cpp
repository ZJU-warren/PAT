#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 1200

char first[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                "jly", "aug", "sep", "oct", "nov", "dec"};
char second[][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                "elo", "syy", "lok", "mer", "jou"};

char str[MAXN],NONE[50];
void PrintStr(int beg){
    int v;
    sscanf(str+beg,"%d",&v);
    if(v < 13)
        printf("%s\n",first[v]);
    else{
        if(v%13)
            printf("%s %s\n",second[v/13],first[v%13]);
        else
            printf("%s\n",second[v/13]);
    }
}
void PrintNum(int beg){
    int blankId,v;
    for(blankId = beg; str[blankId] && str[blankId] != ' '; ++blankId);
    if(!str[blankId]){
        Fin(i,0,12) if(!strcmp(str+beg,first[i])){
            v = i;
            break;
        }
        Fin(i,0,12) if(!strcmp(str+beg,second[i])){
            v = i * 13;
            break;
        }
    }
    else{
        str[blankId] = 0;
        Fin(i,0,12) if(!strcmp(str+beg,second[i])){
            v = i*13;
            break;
        }
        Fin(i,0,13) if(!strcmp(str+blankId+1,first[i])){
            v += i;
            break;
        }
    }
    printf("%d\n",v);
}
int main()
{
    int N,beg;
    while(~SfI(N)){
        gets(NONE);
        Fin(i,1,N){
            memset(str,0,sizeof str);
            gets(str);
            //sprintf(str,"%d",i);
            for(beg = 0;str[beg] == ' '; ++beg);
            if('0' <= str[beg] && str[beg] <= '9')
                PrintStr(beg);
            else
                PrintNum(beg);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)

typedef long long LL;

#define MAXN 1200



int Encode(char c){
    if('a' <= c && c <= 'z')
        return c - 'a';
    else if('0' <= c && c <= '9')
        return 26 + c - '0';
    else
        return 36;
}
char Decode(int x){
    if(0 <= x && x <= 25)
        return x + 'a';
    else if(26 <= x && x <= 35)
        return x - 10 + 'a';
    else
        return '_';
}
int result[MAXN];
/**
    exist 1
    stucked -1
    unKnown 0
**/
char str[MAXN];
int k;
void Analysis(){
    memset(result,0,sizeof result);
    int len = strlen(str),cnt = 1,id;
    if(!len)
        return;
    for(int i = 1; i <= len ; ++i){
        if(str[i] == str[i-1])
            ++cnt;
        else{
            //printf("str[%d] = %c , cnt = %d\n",i-1,str[i-1],cnt);
            id = Encode(str[i-1]);
            if(!result[id])
                result[id] = cnt % k ? 1 : -1;
            else if(!(~result[id]) && cnt % k )
                result[id] = 1;
            cnt = 1;
        }
    }
}
bool checked[MAXN];
void Print(){
    memset(checked,false,sizeof checked);
    int len = strlen(str),id;
    Fin(i,0,len-1){
        id = Encode(str[i]);
        if(!checked[id] && !(~result[id]))
            putchar(str[i]);
        checked[id] = true;
    }
    putchar('\n');
    Fin(i,0,len-1){
        putchar(str[i]);
        id = Encode(str[i]);
        if(!(~result[id]))
            i += (k-1);
    }
    putchar('\n');
}
int main()
{
    while(~SfI(k)){
        SfS(str);
        Analysis();
        Print();
    }
    return 0;
}

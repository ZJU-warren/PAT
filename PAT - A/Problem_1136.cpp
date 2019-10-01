#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define MAXN 1200

struct BigInt{
    int arr[MAXN],len;
    BigInt operator + (BigInt A) {
        BigInt res;
        int maxLen = max(len,A.len);
        Fin(i,len,maxLen)
            arr[i] = 0;
        Fin(i,A.len,maxLen)
            A.arr[i] = 0;
        int carry = 0;
        Fin(i,0,maxLen){
            res.arr[i] = arr[i] + A.arr[i] + carry;
            carry = res.arr[i] >= 10;
            res.arr[i] %= 10;
        }
        res.len = res.arr[maxLen]? maxLen+1 : maxLen;
        return res;
    }
    BigInt Reserve(){
        BigInt res;
        res.len = len;
        Fde(i,len-1,0)
            res.arr[i] = arr[len-i-1];
        return res;
    }
    void Scan(char * p){
        len = strlen(p);
        Fde(i,len-1,0)
            arr[i] = p[len-i-1] - '0';
    }
    void Print(){
        Fde(i,len-1,0)
            putchar('0' + arr[i]);
    }
    bool Match(){
        Fin(i,0,(len-1)/2)
            if(arr[i] != arr[len-1-i])
                return false;
        return true;
    }
};

char strT[MAXN];
BigInt a,b,c;
int main(void){
    while(~scanf("%s",strT)){
        a.Scan(strT);
        int cnt = 0;
        while(!a.Match() && ++cnt <= 10){
            a.Print();
            printf(" + ");
            b = a.Reserve();
            b.Print();
            printf(" = ");
            a = a + b;
            a.Print();
            putchar('\n');
        }
        if(cnt == 11)
            printf("Not found in 10 iterations.\n");
        else{
            a.Print();
            printf(" is a palindromic number.\n");
        }
    }
    return 0;
}

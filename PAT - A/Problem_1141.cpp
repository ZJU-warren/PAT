#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)

typedef long long LL;
#define MAXN 500

inline char Lower(char a){
    return 'a' <= a  && a <= 'z'? a : a - 'A' + 'a';
}
void Format(char *p){
    for(int i = 0; p[i] ; ++i)
        p[i] = Lower(p[i]);
}

struct Sch{
    string name;
    int sb,sa,st,tot,ns;
    Sch(){
        ns = sb = sa = st = 0;
    }
    bool operator < (const Sch & A) const{
        return name < A.name;
    }
    void Sum(){
        tot = (4*sb+9*st)/6 + sa;
    }
    void Print(){
        cout << name ; printf(" ns = %d, (%d, %d, %d)\n",ns,sb,sa,st);
    }
};

set<Sch> S;
set<Sch> :: iterator it;


char strID[MAXN],strName[MAXN];
int score;

void Add(char letter,int score,Sch & x){
    switch(letter){
    case 'A':
        x.sa += score;
        break;
     case 'B':
        x.sb += score;
        break;
     case 'T':
        x.st += score;
        break;
    }
}

void Scan(){
    scanf("%s",strID);
    scanf("%d",&score);
    scanf("%s",strName);
    Format(strName);
    string name = strName;
    Sch x;
    x.name = name;
    it = S.find(x);
    if(it != S.end()){
        x = (*it);
        S.erase(it);
    }
    Add(strID[0],score,x);
    ++x.ns;
    //x.Print();
    S.insert(x);
}

Sch school[105000];
int cntSch;
bool MyCmp(const Sch & A, const Sch & B){
    if(A.tot != B.tot)
        return A.tot > B.tot;
    else if(A.ns != B.ns)
        return A.ns < B.ns;
    return A.name < B.name;
}
int main(void){
    //freopen("e:\\test.txt","r",stdin);
    //freopen("e:\\tsst.txt","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        S.clear();
        Fin(i,1,n)
            Scan();
        cntSch = (int)S.size();
        printf("%d\n",cntSch);
        it = S.begin();
        Fin(i,0,cntSch-1){
            school[i] = (*it);
            school[i].Sum();
            //school[i].Print();
            ++it;
        }
        sort(school,school+cntSch,MyCmp);
        int rk = 1;
        Fin(i,0,cntSch-1){
            if(i && school[i].tot != school[i-1].tot)
                rk = i+1;
            printf("%d ",rk);
            cout << school[i].name;
            printf(" %d %d\n",school[i].tot,school[i].ns);

        }
    }
}

#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define MAXN 50200

#define EXP 0

struct Obj{
    int p,m,f,tot;
    string id;
    Obj(){
        p = m = f = tot = -1;
    }
    void Cal(){
        if(m <= f)
            tot = f;
        else{
            double res = ((double) m*0.4 + (double) f*0.6);
            tot = res-(int)res >= 0.5 ? (int)res + 1 : res;
        }
    }
    bool operator < (const Obj &A) const{
        if(tot != A.tot)
            return tot > A.tot;
        else
            return id < A.id;
    }
}stu[MAXN];

int P,M,N;
set<Obj> S;
set<Obj>::iterator it;
void Scan(){
    string str;
    Obj x;
    Fin(i,1,P){
        cin >> x.id >> x.p;
        if(x.p >= 200)
            S.insert(x);
    }
    Fin(i,1,M){
        cin >> x.id >> x.m;
        if((it = S.find(x)) != S.end()){
            x.p = it->p;
            S.erase(it);
            S.insert(x);
        }
    }

    Fin(i,1,N){
        cin >> x.id >> x.f;
        if((it = S.find(x)) != S.end()){
            x.p = it->p;
            x.m = it->m;
            S.erase(it);
            S.insert(x);
        }
    }
}
int main(){
    //freopen("e:\\test.txt","r",stdin);
    while(~scanf("%d %d %d",&P,&M,&N)){
        S.clear();
        Scan();
        int cnt = S.size();
        it = S.begin();
        int r = 0;
        Fin(i,0,cnt-1){
            stu[r] = (*it);
            stu[r].Cal();
            if(60 <= stu[r].tot && stu[r].tot <= 100)
                ++r;
            ++it;
        }
        sort(stu,stu+r);
        Fin(i,0,r-1){
            Obj & s = stu[i];
            cout << s.id;
            printf(" %d %d %d %d\n",s.p,s.m,s.f,s.tot);
        }
    }
    return 0;
}

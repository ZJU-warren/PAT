#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 10200

struct Obj{
    int par;
    double m_estate,area;
}vex[MAXN];


#define NOT_EXIST -1
struct Rec{
    int id,m;
    double avg_sets,avg_area;
    void SetZero(){
        avg_area = avg_sets = m = 0;
        id = NOT_EXIST;
    }
    void Cal(){
        if(~id){
            avg_sets = avg_sets / m;
            avg_area = avg_area / m;
        }
    }
    bool operator <(const Rec & A) const{
        if(avg_area != A.avg_area)
            return avg_area > A.avg_area;
        return id < A.id;
    }
}record[MAXN];

bool exist[MAXN];
void Init(){
    memset(exist,false,sizeof exist);
    Fin(i,0,MAXN-1){
        vex[i].area = vex[i].m_estate = 0;
        vex[i].par = i;
    }
}
int Find(int x){
    return vex[x].par = vex[x].par == x? x : Find(vex[x].par);
}
void Unite(int x,int y){
    x = Find(x);
    y = Find(y);
    vex[y].par = x;
}

void AddOneInfo(){
    int id,far,mat,k,child;
    scanf("%d %d %d %d",&id,&far,&mat,&k);
    exist[id] = true;
    if(~far){
        Unite(id,far);
        exist[far] = true;
    }
    if(~mat){
        Unite(id,mat);
        exist[mat] = true;
    }
    Fin(i,1,k){
        SfI(child);
        exist[child] = true;
        Unite(id,child);
    }
    SfD(vex[id].m_estate);
    SfD(vex[id].area);
}

map<int,int> parToMinId;
set<int> parExist;
void Modify(){
    parToMinId.clear();
    parExist.clear();
    Fin(i,0,MAXN-1){
        record[i].SetZero();
        if(exist[i]){
            Find(i); ///error 1/
            parExist.insert(vex[i].par);
            if(parToMinId.find(vex[i].par) != parToMinId.end())
                parToMinId[vex[i].par] = min(parToMinId[vex[i].par], i);
            else///error 2 parTo[] can be 0, so couldn't use 0 as a way
                parToMinId[vex[i].par] = i;
            //printf("%04d par = %04d min = %04d\n",i,vex[i].par,parToMinId[vex[i].par]);
        }
    }
    Fin(i,0,MAXN-1) if(exist[i]){
        int id = parToMinId[vex[i].par];
        ++record[id].m;
        record[id].id = id;
        record[id].avg_sets += vex[i].m_estate;
        record[id].avg_area += vex[i].area;
    }
    Fin(i,0,MAXN-1) if(~record[i].id)
        record[i].Cal();
    printf("%d\n",parExist.size());
    sort(record,record+MAXN);
    Fin(i,0,MAXN-1) if(~record[i].id){
        printf("%04d %d %.3lf %.3lf\n",record[i].id
               ,record[i].m,record[i].avg_sets,record[i].avg_area);
    }
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    int N;
    while(~SfI(N)){
        Init();
        Fin(i,1,N)
            AddOneInfo();
        Modify();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 1000

int M,N,S;
set<string> Set;

int main()
{
    //freopen("e:\\test.txt","r",stdin);
    while(~scanf("%d %d %d",&M,&N,&S)){
        Set.clear();
        string str;
        Fin(i,1,S-1)
            cin >> str;
        int id = 0;
        Fin(i,S,M){
            //printf("i = %d id = %d\n",i,id);
            cin >> str;
            if(!(id%N)){
                if(Set.find(str) == Set.end()){
                    Set.insert(str);
                    cout << str << endl;
                    id = (id + 1)%N;
                }
            }
            else
                id = (id + 1)%N;
        }
        if(Set.empty())
            printf("Keep going...\n");
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x, y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define NIL -1

int L, M, N, T;
bool mat[70][1300][130];
bool visit[70][1300][130];
void Init() {
	int x;
	memset(mat, false, sizeof mat);
	Fin(i, 1, L) Fin(j, 1, M) Fin(k, 1, N) {
		SfI(x);
		mat[i][j][k] = (x == 1);
	}
}
struct Node { 
	int i, j, k;
	Node(int i,int j,int k):i(i),j(j),k(k){}
	Node(){}
};
queue<Node> Q;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int Handle() {
	int cnt, res = 0;
	Node u;
	memset(visit, false, sizeof visit);
	Fin(i, 1, L) Fin(j, 1, M) Fin(k, 1, N) if(!visit[i][j][k] && mat[i][j][k]){
		visit[i][j][k] = true;
		Q.push(Node(i, j, k));
		cnt = 0;
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			if (!mat[u.i][u.j][u.k])
				continue;
			++cnt, visit[u.i][u.j][u.k] = true;
			Fin(s, 0, 5) if (!visit[u.i + dx[s]][u.j + dy[s]][u.k + dz[s]]) {
				visit[u.i + dx[s]][u.j + dy[s]][u.k + dz[s]] = true;
				Q.push(Node(u.i + dx[s], u.j + dy[s], u.k + dz[s]));
			}
		}
		if (cnt >= T)
			res += cnt;
		//printf("<%d, %d, %d> = %d\n", i, j, k, cnt);
	}
	return res;
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(M, N)) {
		SfI2(L, T);
		Init();
		printf("%d\n", Handle());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

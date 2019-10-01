#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfD2(x,y) scanf("%lf%lf",&x,&y)
#define SfD3(x,y,z) scanf("%lf%lf%lf",&x,&y,&z)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 600
#define NIL -1
#define EPS 1e-5

double cap, totDis, avg;
int N;
struct Obj {
	double dis, price;
	bool operator<(const Obj &A) const {
		return dis < A.dis;
	}
}station[MAXN];
int S, T;
void Init() {
	S = 0, T = N + 1;
	Fin(i, 1, N) {
		SfD2(station[i].price, station[i].dis);
		if (fabs(station[i].dis - totDis) < EPS) // 防止终点重复
			station[i].price = 0;
	}

	station[S].price;
	station[T].price = 1e7;
	station[S].dis = 0;
	station[T].dis = totDis;
	sort(station + 1, station + N + 1);
#ifdef DEBUG
	Fin(i, 1, N)
		printf("stat[%d], dis = %lf, price = %lf\n", i, station[i].dis, station[i].price);
#endif
}

double Cal(int i, int next,double & left) {
	double res;
	if (next != T && station[i].price < station[next].price) {
#ifdef DEBUG
		printf("dis %.2lf and needTOFull %.2lf, price is %.2lf\n", station[next].dis - station[i].dis, cap - left, station[i].price);
		printf("that cost %.2lf\n", station[i].price * (cap - left));
#endif
		res = station[i].price * (cap - left);
		left = cap - (station[next].dis - station[i].dis) / avg;
	}
	else {
#ifdef DEBUG
		printf("dis %.2lf and need %.2lf, price is %.2lf\n", station[next].dis - station[i].dis, (station[next].dis - station[i].dis) / avg - left, station[i].price);
		printf("that cost %.2lf\n", station[i].price * ((station[next].dis - station[i].dis) / avg - left));
#endif
		res = station[i].price * ((station[next].dis - station[i].dis) / avg - left);
		left = 0;
	}
	return res;
}
double Handle() {
	double cost = 0, left = 0, minCost, minCostAB, minCostBC, minCostAC;
	int j, next;
	if (station[S + 1].dis > EPS) // 初始不可达
		return 0;
	bool flag;
	for (int i = S + 1; i != T;) {
		next = j = i + 1;
		minCost = station[j].price ;
		flag = false;
		while (j <= T && cap * avg + station[i].dis >= station[j].dis) { // 可达
			flag = true;
			if (minCost >= station[j].price) {
				minCostAB = station[i].price * (station[next].dis - station[i].dis) / avg;
				minCostBC = station[next].price * (station[j].dis - station[next].dis) / avg;
				minCostAC = station[i].price * (station[j].dis - station[i].dis) / avg;
				if (minCostAC < minCostAB + minCostBC) {
					minCost = station[j].price;
					next = j;
				}
			}
			++j;
		}
#ifdef DEBUG
		printf("_________________________________\n");
		printf("now at stat[%d], next is stat[%d], loc = %.2lf, left = %.2lf\n", i, next, station[next].dis, left);
#endif // DEBUG
		if (!flag)
			return -(station[i].dis + cap * avg);
		cost += Cal(i, next, left);
		i = next;
	}
	return cost;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	double res;
	while (~SfD3(cap, totDis, avg)) {
		SfI(N);
		Init();
		res = Handle();
		if (fabs(res) < EPS && fabs(station[T].dis) < EPS)
			printf("%.2lf\n", res);
		else if(fabs(res) < EPS)
			printf("The maximum travel distance = %.2lf\n", fabs(res));
		else if(res > 0)
			printf("%.2lf\n", res);
		else
			printf("The maximum travel distance = %.2lf\n", fabs(res));
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 

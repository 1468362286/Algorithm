#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
#define min(a,b) (a>b?b:a)
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
//typedef long long LL;
//typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int n, r ;
struct Point
{
	int x, y;
	double dis;
	bool operator < (const Point&b)const
	{
		return dis > b.dis;
	}
}P[3600]; int pnum;
int d[405][405];
void init()
{
	int i,j;
	pnum = 0;
	for (i = -30; i <= 30; ++i)
	{
		for ( j = -30; j <= 30; ++j)
		{
			double dis = sqrt(i*i + j*j);
			if (dis > r - 1 && dis <= r)
			{
				++pnum;
				P[pnum].x = i;
				P[pnum].y = j;
				P[pnum].dis = dis;
			}
		}
	}
	sort(P + 1, P + pnum + 1);
	//++pnum; P[pnum].x = 0; P[pnum].y = 0;
	for (i = 1; i <= pnum; ++i)
	{
		for ( j = i; j <= pnum; ++j)
		{
			d[i][j] = (P[i].x - P[j].x)*(P[i].x - P[j].x)
					+ (P[i].y - P[j].y)*(P[i].y - P[j].y);
			d[j][i] = d[i][j];
		}
	}
}
int R; int len;
int a[10], A[10];
int ans;
void dfs(int p,int num,int dis)
{
	int i,j;
	if (num == n)
	{
		if (dis <= ans)return;
		ans = dis;
		MC(A, a);
		return;
	}
	if (p > pnum)return;
	//int more = (n - num)*num + (n - num)*(n - num - 1) / 2;
	//if (dis + more*R <= ans)return;

	int top = min(pnum, p + len);
	for ( i = p; i <= top; ++i)
	{
		int tmp = dis; 
		for ( j = 1; j <= num; ++j)tmp += d[i][a[j]];
		double more = 1.01*tmp / num*(n-1)*(n - num);
		if (dis + more < ans)continue;
		a[num + 1] = i; dfs(i, num + 1, tmp);
	}
}
int main()
{
	while (~scanf("%d%d", &n, &r))
	{
		R = (r + r)*(r + r); len = 10;
		init();
		ans = 0;
		dfs(1, 0, 0);
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i)
		{
			printf("%d %d\n", P[A[i]].x, P[A[i]].y);
		}
	}
	return 0;
}
/*
【trick&&吐槽】
1，压缩搜索步长是个剪枝的好技巧
2，剪枝的估价函数要好好设计。
3，这题不能按照过程值的优劣做剪枝，因为是错误的。
4，我们并不需要考虑原点。

【题意】
给你一个网格图，我们只在整点放棋子。
有n（2<=n<=8）个点，它们距离原点的最远距离为r（1<=r<=30）
让你求出一个点集。使得两两之间的距离尽可能远。

【类型】
贪心+爆搜

【分析】
猜想：我们只要贪心，选择的点的范围在[r-1,r]之间即可。
然而，这些点的数量依然很多，直接爆搜还是很可怕。
这里运用贪心猜点位置，+估价函数剪枝和搜索步长剪枝

*/

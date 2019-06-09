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
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 505, M = N*N*6, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int casenum, casei;
int id, ST, ED;
int first[N];
int w[M], c[M], cap[M], cost[M], nxt[M];
int f[N];
int pe[N];
bool e[N];
void ins(int x, int y, int cap_, int cost_)
{
	w[++id] = y;
	cap[id] = cap_;
	cost[id] = cost_;
	nxt[id] = first[x];
	first[x] = id;

	w[++id] = x;
	cap[id] = 0;
	cost[id] = -cost_;
	nxt[id] = first[y];
	first[y] = id;
}
int q[int(2e5)];
int h, t;
struct node
{
	int x, dis;
	node(int x, int dis) :x(x), dis(dis) {}
	bool operator < (const node&b)const
	{
		return dis > b.dis;
	}
};
priority_queue<node>Q;
void inq(int x, int cost_, int pe_)
{
	if (cost_ >= f[x])return;
	f[x] = cost_;
	pe[x] = pe_;
	Q.push(node(x, cost_));
}
bool dijkstra()
{
	while (!Q.empty())Q.pop();
	MS(f, 63);
	MS(e, 0);
	cap[0] = ms63;
	inq(ST, 0, 0);
	while (!Q.empty())
	{
		int x = Q.top().x; Q.pop();
		if (e[x])continue; e[x] = 1;
		if (x == ED)return 1;
		for (int z = first[x]; z; z = nxt[z])
		{
			if (cap[z])inq(w[z], f[x] + cost[z], z);
		}
	}
	return f[ED] < ms63;
}
bool spfa()
{
	MS(e, 0);
	MS(f, 63);
	cap[0] = ms63;
	h = t = 1e5;
	inq(ST, 0, 0);
	while (h<t)
	{
		int x = q[h++]; e[x] = 0;
		for (int z = first[x]; z; z = nxt[z])
		{
			if (cap[z])inq(w[z], f[x] + cost[z], z);
		}
	}
	return f[ED]<ms63;
}
int edge;
void MCMF()
{
	int maxflow = 0;
	int mincost = 0;
	//while (spfa())
	while(dijkstra())
	{
		int flow = ms63;
		int x = ED;
		while (x != ST)
		{
			gmin(flow, cap[pe[x]]);
			x = w[pe[x] ^ 1];
		}
		maxflow += flow;
		mincost += f[ED] * flow;
		x = ED;
		while (x != ST)
		{
			cap[pe[x]] -= flow;
			cap[pe[x] ^ 1] += flow;
			x = w[pe[x] ^ 1];
		}
	}
	//跑完最小费用最大流，maxflow就是组数，mincost就是男生人数，maxflow*2-mincost就是女生人数
	printf("%d %d\n", maxflow, maxflow*2-mincost);
	for (int i = 2; i <= edge; i += 2)if (cap[i] == 0)
	{
		printf("%d %d\n", w[i ^ 1], w[i]);
	}
}
char group[N];
char sex[N];
int n;
int main()
{
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		memset(first, 0, n + 2 << 2); id = 1;
		scanf("%d", &n);
		ST = 0;
		ED = n + 1;
		scanf("%s", group + 1);
		scanf("%s", sex + 1);
		for (int i = 1; i <= n; ++i)
		{
			MS(e, 1); e[i] = 0;
			int g; scanf("%d", &g);
			while (g--)
			{
				int x; scanf("%d", &x);
				e[x] = 0;
			}
			if (group[i] == '0')for (int j = 1; j <= n; ++j)if (e[j] && group[j] == '1')
			{
				ins(i, j, 1, 0);
			}
		}
		edge = id;
		for (int i = 1; i <= n; ++i)
		{
			if (group[i] == '0')ins(ST, i, 1, sex[i]=='1');
			else ins(i, ED, 1, sex[i]=='1');
		}
		MCMF();
	}
	return 0;
}
/*
【题意】
有n（500）个人，这些人每个人不是属于group0就是属于group1。不是女生('0')就是男生('1')
每个人有些人是不想分组的
我们希望使得这n个人分尽可能多的组，
在这个条件下使得女生的人数尽可能多

【类型】
费用流

【分析】
显然这题可以费用流
源点向组0建边，容量为1费用为0
组0的人向组1的人中不是讨厌的人建边，容量为1，费用为2-女生数
组1向汇点建边，容量为1费用为0
然后跑最小费用最大流即可。

当然建图还可以——
源点向组0建边，容量为1费用为:男生?1:0
组0的人向组1的人中不是讨厌的人建边，容量为1，费用为0
组1向汇点建边，容量为1费用为:男生?1:0

不过没什么差别。

【时间复杂度&&优化】
这题很卡常数。
我们可以引用spfa的SLF优化，
或者引用dijkstra费用流
所谓dijkstra费用流，就是用dijkstra代替spfa

【数据】
100
4
1100
0000
0
0
0
0

*/
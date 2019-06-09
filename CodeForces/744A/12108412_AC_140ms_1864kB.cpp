#include <stdio.h>
#include <iostream>
const int maxn = 1010;
int fa[maxn];
int cap[maxn];
int num[maxn];
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
int max(int a, int b) { return a > b ? a : b; }
void unix(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		fa[fx] = fy;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m, k,x,y;
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &cap[i]);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			unix(x, y);
		}
		for (int i = 1; i <= n;i++)
		{
			num[find(i)]++;
		}
		int maxi = 0, lef = n;int ans = 0;
		for (int i = 1; i <= k; i++)
		{
			num[cap[i]] = num[find(cap[i])];
			maxi = max(maxi, num[cap[i]]);
			lef -= num[cap[i]];
			ans += (num[cap[i]] - 1 )* (num[cap[i]]) / 2;
		}
		ans += (lef + maxi)*(lef + maxi - 1) / 2;
		ans -= maxi * (maxi - 1) / 2 + m;
		printf("%d\n", ans);
	}
    return 0;
}
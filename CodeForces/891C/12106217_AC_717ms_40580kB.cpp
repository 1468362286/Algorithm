#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 505050;
int n, m, q;
int pre[N], rk[N];
bool ans[N];
pair<pii, int> e[N];
vector<pii> ee[N], qq[N];

int find(int x)
{
	return pre[x] == x ? x : find(pre[x]);
}

void join(int x, int y)
{
	if (rk[x] == rk[y])
		++rk[x];
	if (rk[x] < rk[y])
		swap(x, y);
	pre[y] = x;
}

void gao(int w,int l,int r)
{
	int ind = qq[w][l].first;
	vector<pair<pii, pii> >sta;
	for (int i = l; i < r; i++)
	{
		int x = qq[w][i].second;
		int u = e[x].first.first, v = e[x].first.second;
		int fu = find(u), fv = find(v);
		if(fu == fv)
		{
			ans[ind] = 1;
		}
		else
		{
			if (rk[fu] < rk[fv])
				swap(fu, fv);
			sta.push_back(make_pair(make_pair(fv, pre[fv]), make_pair(fu, rk[fu])));
			if (rk[fu] == rk[fv])
				++rk[fu];
			pre[fv] = fu;
		}
	}
	for (int i = sta.size() - 1; i >= 0; --i)
	{
		pre[sta[i].first.first] = sta[i].first.second;
		rk[sta[i].second.first] = sta[i].second.second;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n + 1; i++)
	{
		pre[i] = i;
		rk[i] = 1;
	}
	for (int i = 1; i < m + 1; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i] = make_pair(make_pair(u, v), w);
		ee[w].push_back(make_pair(u, v));
	}
	scanf("%d", &q);
	for (int i = 1; i < q + 1; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			qq[e[x].second].push_back(make_pair(i, x));
		}
	}
	for (int w = 1; w < N; w++)
	{
		for (int l = 0, r; l < qq[w].size(); l = r)
		{
			for (r = l; r < qq[w].size() && qq[w][l].first == qq[w][r].first; ++r);
			gao(w, l, r);
		}
		for (int i = 0; i < ee[w].size(); i++)
		{
			int u = ee[w][i].first, v = ee[w][i].second;
			int fu = find(u), fv = find(v);
			if (fu != fv)join(fu, fv);
		}
	}
	for (int i = 1; i < q + 1; i++)
	{
		printf("%s\n", ans[i] ? "NO" : "YES");
	}
	//cin.get();
    return 0;
}
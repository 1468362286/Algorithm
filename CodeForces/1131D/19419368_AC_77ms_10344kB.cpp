#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 2010;
const int inf = 0x7fffffff;
typedef _int64 ll;
vector<int>e[maxn];
char s[maxn][maxn];
int d[maxn],in[maxn];
int n,m;
int p[maxn];
int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int check()
{
	int i,j;
	for( i = 1 ; i <= n+m ; i++)p[i]=i;
	for( i = 1 ; i <= n ; i++)
		for( j = 1 ; j <= m ; j++)
			if(s[i][j]=='=')p[f(i)]=f(j+n);
	for( i = 1 ; i <= n ; i++)
		for( j = 1 ; j <= m ; j++)
		{
			if(s[i][j]=='=')continue;
			if(f(i)==f(j+n))return 0;
			if(s[i][j]=='<')e[f(i)].push_back(f(j+n));
			if(s[i][j]=='>')e[f(j+n)].push_back(f(i));
		}
	for( i = 1 ; i <= n+m ; i++)sort(e[i].begin(),e[i].end());
	for( i = 1 ; i <= n+m ; i++)e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
	for( i = 1 ; i <= n+m ; i++)
		for( j = 0 ; j < e[i].size() ; j++)
			in[e[i][j]]++;
	queue<int>q;
	for( i = 1 ; i <= n+m ; i++)
		if(in[i]==0)q.push(i),d[i]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for( i = 0 ; i < e[now].size() ; i++)
		{
			int nex = e[now][i];
			in[nex]--;
			d[nex]=max(d[nex],d[now]+1);
			if(in[nex]==0)q.push(nex);
		}
	}
	if(*max_element(in+1,in+n+m+1)>0)return 0;
	return 1;

}	
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int i;
	cin>>n>>m;
	for( i = 1 ; i <= n ; i++)
		scanf("%s",s[i]+1);
	if(check())
	{
		puts("Yes");
		for( i = 1 ; i <= n ; i++)cout<<d[f(i)]<<" ";cout<<endl;
		for( i = 1 ; i <= m ; i++)cout<<d[f(i+n)]<<" ";cout<<endl;
	}
	else puts("No");
	return 0;
}		
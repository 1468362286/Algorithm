#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 500010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
vector<int>vec[maxn];
int a[maxn];
int fa[maxn];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void unin(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		fa[fx]=fy;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= n ; i++)
			fa[i]=i;
		for( i = 0 ; i < m ; i++)
		{
			cin>>k;
			if(k==0)continue;
			cin>>a[0];
			for( j = 1 ; j < k ; j++)
			{
				cin>>a[j];
				unin(a[j],a[j-1]);
			}
		}
		for( i = 1 ; i <= n ; i++)
		{
			vec[find(i)].push_back(i);
		}
		for( i = 1 ; i <= n ; i++)
			cout<<vec[find(i)].size()<<" ";
		cout<<endl;
	}
	return 0;
}
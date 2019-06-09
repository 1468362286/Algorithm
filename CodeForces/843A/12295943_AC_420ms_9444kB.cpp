#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <map>
using namespace std;
#define N 100010
int a[N],b[N],vis[N];
map<int,int> mymap;
vector<int> v[N];

void dfs(int id,int num)
{
	v[num].push_back(id);
	vis[id]=true;
	if(!vis[mymap[a[id]]])
	{
		dfs(mymap[a[id]],num);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin.sync_with_stdio(false);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			b[i]=a[i];
			v[i].clear();
		}
		mymap.clear();
		memset(vis,false,sizeof(vis));
		sort(b+1,b+1+n);
		for( i = 1 ; i <= n ; i++)
			mymap[b[i]] = i;
		int cnt=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(!vis[i])
			{
				dfs(i,cnt);
				cnt++;
			}
		}
		cout<<cnt<<endl;
		for( i = 0 ; i < cnt ; i++)
		{
			cout<<v[i].size();
			for( j = 0 ; j < v[i].size() ;j++)
			{
				cout<<" "<<v[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
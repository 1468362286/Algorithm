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
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
struct Node
{
	int d;
	int id;
}node[maxn];
vector<int>vec[maxn];
vector<pair<int,int> >ans;
int d[maxn];
int degree[maxn];
bool cmp(Node A,Node B)
{
	return A.d<B.d;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,k,i,j,z;
	while(cin>>n>>k)
	{
		int flag=0;
		int maxi=-1;
		int cn=0;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>d[i];
			node[i].d=d[i];
			node[i].id=i;
			maxi=max(d[i],maxi);
			vec[d[i]].push_back(i);
			if(d[i]==0)
			{
				cn++;
			}
		}
		if(cn!=1)
		{
			cout<<-1<<endl;
			continue;
		}
		sort(node+1,node+n+1,cmp);
		ans.clear();
		for( i = 1 ; i <= maxi ; i++)
		{
			int cnt=0;
			for( j = 0 ; j < vec[i-1].size() ; j++)
			{
				int from = vec[i-1][j];
				for( z = cnt ; z < vec[i].size() &&degree[from]<k; z++)
				{
					int to = vec[i][z];
					ans.push_back(make_pair(from,to));
					degree[from]++,degree[to]++;
				}
				cnt=z;
			}
			if(cnt<vec[i].size())
				flag=1;
		}
		if(flag)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<ans.size()<<endl;
			for( i = 0 ; i < ans.size() ; i++)
			{
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
			}
		}
	}
	return 0;
}
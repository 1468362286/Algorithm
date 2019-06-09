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
const int maxn=100010;
const int inf = 0x7fffffff;
typedef _int64 ll;
vector<int>vec[maxn];
vector<int>ver,ans;
int c[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,j,x,y;
	while(cin>>n)
	{
		int root=0;
		ver.clear();
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		memset(c,0,sizeof(c));
		for( i = 1 ; i <= n ; i++)
		{
			cin>>x>>y;
			if(x==-1)
			{
				root=i;
				continue;
			}
			vec[x].push_back(i);
			c[i]=y;
			if(y==1)
			{
				ver.push_back(i);
			}
		}
		sort(ver.begin(),ver.end());
		/*
		for( i = 0 ; i < ver.size() ; i++)
			cout<<ver[i]<<" ";
		cout<<endl;*/
		ans.clear();
		for( i = 0 ; i < ver.size() ; i++)
		{
			int flag=0;
			if(ver[i]==root)continue;
			for( j = 0 ; j < vec[ver[i]].size() ; j++)
			{
				if(c[vec[ver[i]][j]]==0)
				{
					flag=1;
					break;
				}
			}
			if(!flag)ans.push_back(ver[i]);
		}
		if(ans.size()==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}	
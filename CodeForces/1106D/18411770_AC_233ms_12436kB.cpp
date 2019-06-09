#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
#include <set>
using namespace std;
const int maxn = 300010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
double min(double a,double b){return a>b?b:a;}
typedef _int64 ll;
vector<int>vec[maxn];
int vist[maxn];
vector<int>ans;
set<int> myset;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,i,x,y;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < m ; i++)
		{
			cin>>x>>y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		myset.insert(1);
		while(1)
		{
			if(ans.size()==n)
				break;
			x = (*myset.begin());
			vist[x]=1;
			ans.push_back(x);
			myset.erase(myset.begin());
			for( i = 0 ; i < vec[x].size() ; i++)
				if(!vist[vec[x][i]])
				{
					myset.insert(vec[x][i]);
				}
		}
		for( i = 0 ; i < n ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
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
const int maxn = 110;
const int inf = 0x7fffffff;
typedef long long ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
vector<pair<int,int> >vec; 

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,u,v,i;
	while(cin>>n)
	{
		vec.clear();
		vec.push_back(make_pair(0,0));
		for( i = 1 ; i <= n ; i++)
		{
			cin>>u>>v;
			if(i>1&&(vec[vec.size()-1]).first==u&&(vec[vec.size()-1]).second==v)
				continue;
			vec.push_back(make_pair(u,v));
		}
		ll ans=0;
		for( i = 1 ; i < vec.size() ; i++)
		{
			int l = max(vec[i-1].first,vec[i-1].second);
			int r = min(vec[i].first,vec[i].second);
			if(r<l)continue;
			ans+=r-l+1;
			if(vec[i-1].first==vec[i-1].second)
				ans--;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}	
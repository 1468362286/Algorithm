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
const int maxn = 10010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
map<int,int>mymap;
priority_queue<pair<int,int> >Q;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,X,i;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>X;
			mymap[X]++;
		}
		map<int,int>::iterator it;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			Q.push(make_pair((*it).second,(*it).first));
		}
		if(Q.size()<3)
		{
			cout<<0<<endl;
			continue;
		}
		vector<int>ans,vec;
		ans.clear();
		pair<int,int>x,y,z;
		while(Q.size()>=3)
		{ 
			x=Q.top();
			Q.pop();
			y=Q.top();
			Q.pop();
			z=Q.top();
			Q.pop();
			if(x.first-1!=0)Q.push(make_pair(x.first-1,x.second));
			if(y.first-1!=0)Q.push(make_pair(y.first-1,y.second));
			if(z.first-1!=0)Q.push(make_pair(z.first-1,z.second));
			vec.clear();
			vec.push_back(x.second),vec.push_back(y.second),vec.push_back(z.second);
			sort(vec.begin(),vec.end());
			for( i = 2 ; i >= 0 ; i--)
				ans.push_back(vec[i]);
		}
		cout<<ans.size()/3<<endl;
		for( i = 0 ; i < ans.size() ; i+=3)
		{
			cout<<ans[i]<<" "<<ans[i+1]<<" "<<ans[i+2]<<endl;		
		}
	}
	return 0;
}

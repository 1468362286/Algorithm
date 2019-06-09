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
int min(int a,int b){return a>b?b:a;}
map<int,vector<pair<int,int> > >mymap;
int a[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,l,r;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( r = 1 ; r <= n ; r++)
		{
			int sum=0;
			for( l = r ; l >= 1 ; l--)
			{
				sum+=a[l];
				mymap[sum].push_back(make_pair(r,l));
			}
		}
		map<int,vector<pair<int,int> > >::iterator it;
		vector<pair<int,int> >tmp,ans;
		int maxi=0;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			tmp = (*it).second;
			int cnt=1;
			int right=tmp[0].first;
			for( i = 1 ; i < tmp.size() ; i++)
			{
				if(tmp[i].second>right)
				{
					cnt++;
					right = tmp[i].first;
				}
			}
			if(cnt>maxi)
			{
				maxi=cnt;
				ans=tmp;
			}
		}
		cout<<maxi<<endl;
		int right=ans[0].first;
		cout<<ans[0].second<<" "<<ans[0].first<<endl;
		for( i = 1 ; i < ans.size() ; i++)
		{
			if(ans[i].second>right)
			{
				cout<<ans[i].second<<" "<<ans[i].first<<endl;
				right = ans[i].first;
			}
		}
	}
	return 0;
}	
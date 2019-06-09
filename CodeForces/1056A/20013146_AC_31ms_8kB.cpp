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
const int maxn = 2010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,n,x,i;
	map<int,int>mymap;
	mymap.clear();
	cin>>t;
	int T=t;
	while(t--)
	{
		cin>>n;
		for( i = 0 ; i < n ; i++)
			cin>>x,mymap[x]++;
		map<int,int>::iterator it;
		vector<int>ans;
		ans.clear();
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			if((*it).second==T)
			{
				ans.push_back((*it).first);
			}
		}
		sort(ans.begin(),ans.end());
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
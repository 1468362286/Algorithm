#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int maxn = 100010;
int vist[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
map<int,int>mymap;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,x,i;
	while(cin>>n)
	{
		mymap.clear();
		int maxi = 0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			mymap[x]++;
			maxi=max(x,maxi);
		}
		for( i = 1 ; i <= maxi ; i++)
		{
			if(maxi%i==0)
			{
				mymap[i]--;
			}
		}
		map<int,int>::iterator it;
		int ans=0;
		for( it = mymap.begin() ; it!=mymap.end() ;it++)
		{
			if((*it).second)
			ans=max(ans,(*it).first);
		}
		cout<<maxi<<" "<<ans<<endl;
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int a[maxn],b[maxn];
map<pair<int,int>,int>mymap;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i];
		mymap.clear();
		int cnt=0;
		for( i = 0 ; i < n ; i++)
		{
			if(a[i]!=0)
			{
				int g = gcd(a[i],b[i]);
				a[i]/=g;
				b[i]/=g;
				mymap[make_pair(a[i],b[i])]++;
			}
			else if(a[i]==0&&b[i]==0)
				cnt++;
		}
		map<pair<int,int>,int>::iterator it;
		int ans=0;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			ans=max(ans,(*it).second);
		}
		cout<<ans+cnt<<endl;
	}
	return 0;
}
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
map<int,int>mymap;
vector<int>vec;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,k,i;
	while(cin>>n>>m>>k)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i],b[i]=a[i];
		sort(b,b+n);
		int cnt=n-1;
		ll ans=0;
		mymap.clear();
		int K=k;
		k*=m;
		while(k--)
		{
			ans+=b[cnt];
			mymap[b[cnt--]]++;
		}
		cnt=0;
		vec.clear();
		for( i = 0 ; i < n ; i++)
		{
			if(mymap.find(a[i])!=mymap.end()&&mymap[a[i]]!=0)
			{
				mymap[a[i]]--;
				cnt++;
				if(cnt==m)
					vec.push_back(i+1),cnt=0;
			}
		}
		printf("%I64d\n",ans);
		for( i = 0 ; i < K-1 ; i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}
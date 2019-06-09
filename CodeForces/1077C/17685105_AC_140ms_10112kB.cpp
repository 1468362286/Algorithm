#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 200010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
ll a[maxn];
map<ll,int>mymap;
vector<int>ans;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		ll sum=0;
		ans.clear();
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			scanf("%I64d",&a[i]),sum+=a[i],mymap[a[i]]++;
		for( i = 0 ; i < n ; i++)
		{
			ll tmp = sum-a[i];
			if(!(tmp&1))
			{
				ll x = tmp/2;
				if(x!=a[i]&&mymap.find(x)!=mymap.end())
					ans.push_back(i+1);
				if(x==a[i]&&mymap.find(x)!=mymap.end()&&mymap[x]>1)
					ans.push_back(i+1);
			}
		}
		cout<<ans.size()<<endl;
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		if(ans.size())
			cout<<endl;
	}
	return 0;
}
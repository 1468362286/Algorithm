#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200010;
int a[maxn];
vector<int> vec;
typedef _int64 ll;
int main()
{
	int n,s,i,x;
	while(cin>>n>>s)
	{
		vec.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		ll ans=0;
		for( i = 0 ; i < n/2 ; i++)
		{
			if(vec[i]>s)
			{
				ans+=vec[i]-s;
			}
			if(vec[n-1-i]<s)
			{
				ans+=s-vec[n-1-i];
			}
		}
		ans+=abs(vec[n/2]-s);
		printf("%I64d\n",ans);
	}
	return 0;
}

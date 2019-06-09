#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int a[maxn];
int n,m;
bool can(int i)
{
	ll sum=0;
	for(int j = 0 ; j < n ; ++j)
		sum+=max(a[j]-j/i,0);
	return sum>=m;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int i;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n,greater<int>());
		int l=1,r=n;
		while(r-l>1)
		{
			int mid = (l+r)>>1;
			if(can(mid))r=mid;
			else l=mid;
		}
		if(can(l))cout<<l<<endl;
		else if(can(r))cout<<r<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
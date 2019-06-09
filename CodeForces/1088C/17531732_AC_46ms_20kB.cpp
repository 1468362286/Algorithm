#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 2010;
const int inf = 0x3f3f3f3f;
ll min(ll a,ll b){return a>b?b:a;}
int a[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		cout<<n+1<<endl;
		cout<<"2 "<<n<<" "<<"1"<<endl;
		cout<<"1 "<<n<<" "<<"999999"<<endl;
		for( i = 1 ; i <= n-1 ; i++)
		{
			cout<<"2 "<<i<<" "<<999999-i+1<<endl;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int a[maxn];
inline int min(int a,int b){return a>b?b:a;}
int main()
{
	int n,m,x,i;
	while(cin>>n>>m)
	{
		int ans=inf;
		memset(a,0,sizeof(a));
		for( i = 0 ; i < m ; i++)
		{
			cin>>x;
			a[x]++;
		}
		for( i = 1 ; i <= n ; i++)
		{
			ans=min(ans,a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
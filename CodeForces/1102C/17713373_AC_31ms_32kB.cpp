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
const int maxn = 5010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i,n,x,y;
	while(cin>>n>>x>>y)
	{
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			if(a[i]<=x)
			{
				ans++;
			}
		}
		if(x>y)
			cout<<n<<endl;
		else
			cout<<(ans+1)/2<<endl;
	}
	return 0;
}
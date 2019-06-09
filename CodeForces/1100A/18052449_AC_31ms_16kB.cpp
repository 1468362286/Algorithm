#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const ll mod = 1000000007;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
const int maxn=100007;
int a[110];
int b[110];
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,k,i,j;
	while(cin>>n>>k)
	{
		int ans=0;
		for( i = 1 ; i <= n ; i++)cin>>a[i];
		for( i = 1 ; i <= k ; i++)
		{
			memcpy(b,a,sizeof(b));
			for( j = 0 ; j <= n/k ; j++)
			{
				int tmp = i+j*k;
				if(tmp<=n)
					b[tmp]=0;
			}
			int c=0;
			for( j = 1 ; j <= n ; j++)
			{
				if(b[j]==1)
					c++;
				else if(b[j]==-1)
					c--;
			}
			if(c<0)c=-c;
			ans=max(ans,c);
		}
		cout<<ans<<endl;
	}
    return 0;
}
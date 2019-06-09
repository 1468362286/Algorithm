#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1000100;
int a[maxn];
int hash1[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(~scanf("%d",&n))
	{
		memset(hash1,0,sizeof(hash1));
		int cnt = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			hash1[a[i]]++;
		}
		//sort(a,a+n);
		int ans = 0;
		for( i = 0 ; i < maxn ; i++)
		{
			hash1[i+1]+=hash1[i]/2;
			hash1[i]%=2;
			if(hash1[i])
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
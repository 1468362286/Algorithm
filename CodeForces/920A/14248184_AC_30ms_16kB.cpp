
 #include <iostream>
#include <string>
using namespace std;
const int maxn = 220;
int a[maxn];
int vist[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int T,i,n,k;
	cin>>T;
	while(T--)
	{
		memset(vist,0,sizeof(vist));
		cin>>n>>k;
		for( i = 0 ; i < k ; i++)
			cin>>a[i];
		int times=0;
		int ans=0;
		while(1)
		{
			int cnt=0;
			for( i = 1 ; i <= n ; i++)
				if(vist[i])
					cnt++;
			if(cnt==n)
			{
				ans= times;
				break;
			}
			times++;
			for( i = 0 ; i < k ; i++)
			{
				if(times==1)
					vist[a[i]]=1;
				else
				{
					if(a[i]-(times-1)>=1)
						vist[a[i]-(times-1)]=1;
					if(a[i]+(times-1)<=n)
						vist[a[i]+(times-1)]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
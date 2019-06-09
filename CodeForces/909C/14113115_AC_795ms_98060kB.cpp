#include <iostream>
#include <string>
using namespace std;

#define N 5005
#define MOD 1000000007

int n;
int dp[N][N];
char c[N];

void update(int *dat,int k,int x)
{
	while(k>0)
	{
		dat[k]=(dat[k]+x)%MOD;
		k-=k&-k;
	}
}

int query(int *dat,int k)
{
	int sum=0;	
	while(k<=n)
	{
		sum=(sum+dat[k])%MOD;
		k+=k&-k;
	}
	return (sum%MOD+MOD)%MOD;
}

void sec(int *dat,int l,int r,int x)
{
	update(dat,r,x);
	update(dat,l-1,-x);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	cin>>n;
	for( i = 1 ; i <= n ; i++)
		cin>>c[i];
	memset(dp,0,sizeof(dp));
	sec(dp[1],1,1,1);
	for( i = 1; i <= n ; i++)
	{
		for( j = 1 ;j <= i ; j++)
		{
			int now=query(dp[i],j);
			if(now)
			{
				if(c[i]=='f')
					sec(dp[i+1],j+1,j+1,now);
				else
					sec(dp[i+1],1,j,now);
			}
		}
	}
	int ans=0;
	for( i = 1 ; i <= n ; i++)
		ans=(ans+query(dp[n],i))%MOD;
	cout<<ans<<endl;
	return 0;
}
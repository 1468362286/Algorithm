#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 200010;
const int inf=0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn],b[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int i,n,k;
	while(cin>>n>>k)
	{
		int mina = inf;
		int maxi = 0;
		for( i = 1 ; i <= n ; i++)
			cin>>a[i],mina=min(mina,a[i]),maxi=max(maxi,a[i]);
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		memset(b,0,sizeof(b));
		for( i = 1 ; i <= n ; i++)
		{
			a[i]-=mina;
			b[1]++;
			b[a[i]+1]--;
		}
		for( i = 2 ; i <= n ; i++)
		{
			if(a[i]!=a[1])
				break;
			if(i==n)
			{
				cout<<0;
				return 0;
			}
		}
		for( i = 2 ; i <= maxi ; i++)
			b[i]+=b[i-1];
		int tmp=0,ans=1;
		for( i = 1 ; i <= maxi ; i++)
		{
			if(tmp+b[i]<=k)
				tmp+=b[i];
			else
				ans++,tmp=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
const int maxn = 3010;
const int inf=0x3f3f3f3f;
int a[maxn],b[maxn];
inline int min(int a,int b){return a>b?b:a;}

int solve1(int n)
{
	int i,j,k;
	int ans=inf;
	for( i = 0 ; i < n ; i++)
		for( j = i+1 ; j < n ; j++)
		{
			if(a[i]<a[j])
			{
				for( k = j+1 ; k < n ; k++)
				{
					if(a[j]<a[k])
					{
						ans=min(ans,b[i]+b[j]+b[k]);
					}
				}
			}
		}
	return ans;
}
int solve(int n)
{
	int ans=inf;
	int ans1;
	int ans2;
	int i,j,k;
	for( j = 1 ; j < n-1 ; j++)
	{
		ans1=inf;
		for( i = j-1 ; i >= 0 ; i--)
			if(a[j]>a[i])
			{
				ans1=min(ans1,b[i]);
			}
		ans2=inf;
		for( k = j+1 ;  k < n ; k++)
		{
			if(a[j]<a[k])
				ans2=min(ans2,b[k]);
		}
		ans=min(ans,ans1+ans2+b[j]);
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i];
		int ans=solve(n);
		if(ans==inf)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
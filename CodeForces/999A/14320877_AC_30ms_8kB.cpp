#include <iostream>
#include <string>
#include <queue>
using namespace std;
int a[110];
int n,k;

int solve()
{
	int ans=0;
	int i,l=0,r=n+1;
	for( i = 1 ; i <= n ; i++)
	{
		if(a[i]>k)
		{
			l=i;
			break;
		}
	}
	if(l==0)
		return n;
	for( i = n ; i >= 1 ; i--)
	{
		if(a[i]>k)
		{
			r=i;
			break;
		}
	}
	if(l<=r)
		return n-(r-l+1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n>>k)
	{
		for(int i = 1 ; i <= n ; i++)
			cin>>a[i];
		cout<<solve()<<endl;
	}
	return 0;
}
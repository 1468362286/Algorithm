#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int a[maxn];
int v[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		int maxi=0;
		int maxii=0;
		for( i = 0 ; i < n  ; i++)
		{
			if(maxi<a[i])
			{
				maxii=maxi;
				maxi=a[i];
				v[maxi]--;
			}
			else
			{
				if(a[i]>maxii)
				{
					maxii=a[i];
					v[maxi]++;
				}
			}
		}
		int ans=-inf;
		int ansi=0;
		for( i = 1 ; i <= n ; i++)
			if(ans<v[i])
			{
				ans=v[i];
				ansi=i;
			}
			else if(ans==v[i]&&ansi>i)
			{
				ansi=i;
			}
		cout<<ansi<<endl;
	}
	return 0;
}
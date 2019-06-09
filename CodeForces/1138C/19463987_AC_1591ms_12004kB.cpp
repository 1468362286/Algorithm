#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int z[maxn][maxn],a[maxn][maxn],b[maxn][maxn],tpa[maxn],tpb[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,i,j;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
			{
				cin>>z[i][j];
				a[i][j]=b[j][i]=z[i][j];
			}
		int al,bl;
		for( i = 1 ; i <= n ; i++)
		{
			sort(a[i]+1,a[i]+1+m);
			tpa[i]=unique(a[i]+1,a[i]+m+1)-(a[i]+1);
		}
		for( i = 1 ; i <= m ; i++)
		{
			sort(b[i]+1,b[i]+n+1);
			tpb[i]=unique(b[i]+1,b[i]+n+1)-(b[i]+1);
		}
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= m ; j++)
			{
				al=lower_bound(a[i],a[i]+tpa[i],z[i][j])-a[i];
				bl=lower_bound(b[j],b[j]+tpb[j],z[i][j])-b[j];
				cout<<max(al,bl)+max(tpa[i]-al,tpb[j]-bl)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}		
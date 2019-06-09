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
const int maxn = 110;
const int inf = 0x3fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn][maxn];
int b[maxn][maxn];

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
				cin>>a[i][j];
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
				cin>>b[i][j];
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
				if(a[i][j]>b[i][j])
					swap(a[i][j],b[i][j]);
		int flag=0;
		for( i = 1 ; i <= n&&!flag ; i++)
			for( j = 1 ; j <= m&&!flag ; j++)
			{
				if((i+1<=n&&a[i][j]>=a[i+1][j])||(j+1<=m&&a[i][j]>=a[i][j+1]))
					flag=1;
				if((i+1<=n&&b[i][j]>=b[i+1][j])||(j+1<=m&&b[i][j]>=b[i][j+1]))
					flag=1;
			}
		if(flag)cout<<"Impossible"<<endl;
		else cout<<"Possible"<<endl;
	}
	return 0;
}		
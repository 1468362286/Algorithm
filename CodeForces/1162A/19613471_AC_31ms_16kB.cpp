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
int a[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,h,m,i,j,l,r,x;
	while(cin>>n>>h>>m)
	{
		memset(a,-1,sizeof(a));
		for( i = 0 ; i < m ; i++)
		{
			cin>>l>>r>>x;
			for( j = l ; j <= r ; j++)
				if(a[j]==-1)a[j]=x;
				else a[j]=min(a[j],x);
		}
		int ans=0;
		for( i = 1 ; i <= n ; i++)
			if(a[i]==-1)ans+=(h*h);
			else ans+=a[i]*a[i];
		cout<<ans<<endl;
	}
	return 0;
}		
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 110;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
int vist[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,m,i,j,x,y;
	while(cin>>n>>m)
	{
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			for( j = 0 ; j < x ; j++)
				cin>>y,vist[y]=1;
		}
		int flag=0;
		for( i = 1 ; i <= m ; i++)
			if(!vist[i])
			{
				flag=1;
				break;
			}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 10010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int d=1,ans=0;
		while(d<=n)
		{
			while(1)
			{
				if(d==a[d])
					break;
				for( i = d ; i <= a[d] ; i++)
					d=max(a[d],a[i]);
			}
			d++;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
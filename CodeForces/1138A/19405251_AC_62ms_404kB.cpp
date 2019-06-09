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
const int maxn = 100010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

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
		int cnt=1;
		int pre=0;
		for( i = 2 ; i <= n ; i++)
		{
			if(a[i]!=a[i-1])
			{
				pre=cnt;
				break;
			}
			else
				cnt++;
		}
		cnt=1;
		int ans=-1;
		for( i=i+1 ; i <= n ; i++)
		{
			if(a[i]!=a[i-1])
			{
				ans=max(ans,min(cnt,pre));
				pre=cnt;
				cnt=1;
			}
			else
				cnt++;
		}
		if(cnt)ans=max(ans,min(cnt,pre));
		cout<<2*ans<<endl;
	}	
	return 0;
}		
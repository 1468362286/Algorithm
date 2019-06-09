#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,l,r;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for( l = 0,r=0 ; r < n ; r++)
		{
			if(a[r]-a[l]>5)
			{
				ans=max(ans,r-l);
				l++;
			}
		}
		ans=max(ans,r-l);
		cout<<ans<<endl;
	}
	return 0;
}
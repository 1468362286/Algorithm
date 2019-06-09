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
const int maxn=400010;
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
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = n ; i < 2*n ; i++)
			a[i]=a[i-n];
		int ans=0,cnt=0;
		for( i = 0 ; i < 2*n ; i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
			else
			{
				ans=max(ans,cnt);
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
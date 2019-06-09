#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 110;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int i,n;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		int l;
		int maxi = 1;
		for( l = 0 ; l < n-1 ; l++)
		{
			int pos=l;
			while(l<n-1&&a[l]+1==a[l+1])
			{
				l++;
			}
			if(l-pos+1>maxi)
			{
				maxi=l-pos+1;
			}
		}
		int cnt1=1;
		if(a[0]==1)
		{
			for( i = 0 ; i < maxi-1 ; i++)
			{
				if((a[i]+1)!=a[i+1])
				{
					break;
				}
				else cnt1++;
			}
		}
		int cnt2=1;
		if(a[n-1]==1000)
		{
			for( i = 0 ; i < maxi-1 ; i++)
			{
				if((a[n-1-i]-1)!=a[n-1-i-1])
				{
					break;
				}
				else
					cnt2++;
			}
		}
		if(cnt1==maxi||cnt2==maxi)
		{
			cout<<maxi-1<<endl;
		}
		else cout<<maxi-2<<endl;
	}
    return 0;
}
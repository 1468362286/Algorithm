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
		a[0]=0,a[n+1]=1001;
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int l;
		int maxi = 1;
		for( l = 0 ; l <= n ; l++)
		{
			int pos=l;
			while(l<=n&&a[l]+1==a[l+1])
			{
				l++;
			}
			if(l-pos+1>maxi)
			{
				maxi=l-pos+1;
			}
		}
		if(maxi==1)cout<<"0"<<endl;
		else cout<<maxi-2<<endl;
	}
    return 0;
}
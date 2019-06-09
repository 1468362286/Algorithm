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
const int maxn = 1010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,i,j,x;
	while(cin>>n)
	{
		int maxi=0,mina=inf;
		for( i = 0 ; i < n ; i++)
			cin>>a[i],maxi=max(maxi,a[i]),mina=min(mina,a[i]);
		int ans=inf;
		for( i = mina ; i <= maxi ; i++)
		{
			int tmp=0;
			for( j = 0 ; j < n ; j++)
			{
				if(a[j]>i)
				{
					tmp+=a[j]-(i+1);
				}
				else if(a[j]<i)
					tmp+=i-1-a[j];
			}
			if(tmp<ans)
			{
				ans=tmp;
				x = i;
			}
		}
		cout<<x<<" "<<ans<<endl;
	}
    return 0;
}
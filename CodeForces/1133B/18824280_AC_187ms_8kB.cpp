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
int min(int a,int b){return a>b?b:a;}
int a[110];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,k,i,x;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			a[x%k]++;
		}
		int ans=a[0]/2*2;
		for( i = 1 ; i < k ; i++)
		{
			if(i==k-i)
				ans+=a[i]/2*2;
			else
				ans+=min(a[i],a[k-i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
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
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int b[maxn];
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
		sort(a+1,a+n+1);
		int cnt=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(i&1)
				b[1+cnt]=a[i];
			else
				b[n-cnt]=a[i],cnt++;
		}
		for( i = 1 ; i <= n ; i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}		
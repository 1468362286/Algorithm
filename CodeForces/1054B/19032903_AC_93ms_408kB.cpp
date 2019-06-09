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
const int maxn=100010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
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
		if(a[1]!=0)
		{
			cout<<1<<endl;
			continue;
		}
		int x= -1;
		int maxi = a[1];
		for( i = 2 ; i <= n ; i++)
		{			
			if(a[i]>maxi+1)
			{
				x=i;
				break;
			}
			maxi=max(maxi,a[i]);
		}
		cout<<x<<endl;
	}
	return 0;
}	
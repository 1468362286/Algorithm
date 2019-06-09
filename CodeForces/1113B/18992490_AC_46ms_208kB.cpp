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
const int maxn=50010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,j;
	while(cin>>n)
	{
		int sum=0;
		int mina=inf;
		int x=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i],sum+=a[i];
			if(mina>a[i])
			{
				mina=a[i];
				x = i;
			}
		}
		mina=sum;
		for( i = 0 ; i < n ; i++)
		{
			if(i!=x)
			{
				for( j = 2 ; j <= a[i] ; j++)
				{
					if(a[i]%j==0)
					mina=min(mina,sum-a[x]-a[i]+a[x]*j+a[i]/j);	
				}
			}
		}
		cout<<mina<<endl;
	}
	return 0;
}
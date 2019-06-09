#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
#include <set>
using namespace std;
const int maxn = 200010;
const int inf=0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int a[maxn];
int pre_sum1[maxn];
int pre_sum2[maxn];
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
		int l=0,r=0;
		memset(pre_sum1,0,sizeof(pre_sum1));
		memset(pre_sum2,0,sizeof(pre_sum2));
		for( i = 1 ; i <= n ; i++)
		{
			if(i&1)
			{
				l+=a[i];
				pre_sum1[i]=l;
				pre_sum2[i]=r;
			}
			else
			{
				r+=a[i];
				pre_sum2[i]=r;
				pre_sum1[i]=l;
			}
		}
		/*
		for( i = 1 ; i <= n ; i++)
			cout<<pre_sum1[i]<<" ";
		cout<<endl;
		for( i = 1 ; i <= n ; i++)
			cout<<pre_sum2[i]<<" ";
		cout<<endl;*/
		int ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			l = pre_sum1[i-1]+(pre_sum2[n]-pre_sum2[i]);
			r = pre_sum2[i-1]+(pre_sum1[n]-pre_sum1[i]);
			if(l==r)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
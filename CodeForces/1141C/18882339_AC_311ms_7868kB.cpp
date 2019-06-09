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
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int pre_sum[maxn];
set<int>myset;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		myset.clear();
		for( i = 1 ; i < n ; i++)
			cin>>a[i],pre_sum[i]=pre_sum[i-1]+a[i],myset.insert(pre_sum[i]);
		if(myset.size()<n-1||myset.find(0)!=myset.end())
		{
			cout<<-1<<endl;
			continue;
		}
		int l=1,r=n;
		for( i = 1 ; i < n ; i++)
		{
			if(pre_sum[i]<0)
			{
				l=max(l,1-pre_sum[i]);
			}
			else if(pre_sum[i]>0)
			{
				r=min(r,n-pre_sum[i]);
			}
		}
		if(l==r)
		{
			cout<<l<<" ";
			for( i = 1 ; i < n ; i++)
			{
				l+=a[i];
				cout<<l<<" ";
			}
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}
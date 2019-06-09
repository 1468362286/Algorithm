#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 200010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int a[]={ 4, 8, 15, 16, 23, 42};
int ans[10];
int vist[10];
set<int>myset;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int x1,x2,i;
	for( i = 0 ; i < 6 ; i++)
	{
		myset.insert(a[i]);
	}
	memset(vist,0,sizeof(vist));
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&x1);
	for( i = 0 ; i < 6 ; i++)
	{
		if(x1%a[i]==0&&myset.find(x1/a[i])!=myset.end())
		{
			vist[a[i]]=1;
			vist[x1/a[i]]=1;
			break;
		}
	}
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d",&x2);
	for( i = 0 ; i < 6 ; i++)
	{
		if(x2%a[i]==0&&myset.find(x2/a[i])!=myset.end())
		{
			if(vist[a[i]])
			{
				ans[2]=a[i];
				ans[3]=x2/a[i];
			}
			else if(vist[x2/a[i]])
			{
				ans[2]=x2/a[i];
				ans[3]=a[i];
			}
			break;
		}
	}
	ans[1]=x1/ans[2];
	memset(vist,0,sizeof(vist));
	printf("? 4 5\n");
	fflush(stdout);
	scanf("%d",&x1);
	for( i = 0 ; i < 6 ; i++)
	{
		if(x1%a[i]==0&&myset.find(x1/a[i])!=myset.end())
		{
			vist[a[i]]=1;
			vist[x1/a[i]]=1;
		}
	}
	printf("? 5 6\n");
	fflush(stdout);
	scanf("%d",&x2);
	for( i = 0 ; i < 6 ; i++)
		if(x2%a[i]==0&&myset.find(x2/a[i])!=myset.end())
		{
			if(vist[a[i]])
			{
				ans[5]=a[i];
				ans[6]=x2/a[i];
			}
			else if(vist[x2/a[i]])
			{
				ans[5]=x2/a[i];
				ans[6]=a[i];
			}
			break;
		}
	ans[4]=x1/ans[5];
	printf("!");
	for( i = 1 ; i <= 6 ; i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
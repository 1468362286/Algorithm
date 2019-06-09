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
const int maxn = 5010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int ans[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,x1,x2,x3,x,i;
	scanf("%d",&n);
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d",&x1);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d",&x2);
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d",&x3);
	ans[3]=(x1+x2+x3)/2-x1;
	ans[1]=(x1+x2+x3)/2-x2;
	ans[2]=(x1+x2+x3)/2-x3;
	for( i = 4 ; i <= n ; i++)
	{
		printf("? %d %d\n",i-1,i);
		fflush(stdout);
		scanf("%d",&x);
		ans[i]=x-ans[i-1];
	}
	printf("!");
	for( i = 1 ; i <= n ; i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
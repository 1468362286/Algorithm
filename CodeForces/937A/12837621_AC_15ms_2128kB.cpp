#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,x;
	while(~scanf("%d",&n))
	{
		int cnt=0; 
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			if(x>0)
				a[cnt++]=x;
		}
		sort(a,a+cnt);
		int ans = unique(a,a+cnt)-a;
		printf("%d\n",ans);
	}
	return 0;
}
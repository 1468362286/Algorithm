#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef  _int64 ll;
const int maxn = 200010;
int a[maxn];
int b[maxn];
int min(int a,int b){return a>b?b:a;}
int vist[maxn];
int main()
{	
	//freopen("in.txt","r",stdin);
	int n,i,tmp,zz;
	ll ans;
	while(~scanf("%d",&n))
	{
		int cnt1 = 0;
		int cnt2 = 0;
		int zero = 0;
		int gg = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",a+i);
			tmp = a[i];
			zz = sqrt(tmp*1.0);
			if(zz*zz==tmp)
				vist[i] = 1;
			if(tmp==0)
				zero++;
			if(vist[i])
			{
				cnt1++;
				continue;
			}
			else
			{
				if(tmp-zz*zz>(zz+1)*(zz+1)-tmp)
				{
					b[gg++] = (zz+1)*(zz+1)-tmp;
				}
				else
					b[gg++] = tmp-zz*zz;
			}
		}
		cnt2 = n-cnt1;
		ans = 0;
		if(cnt1==cnt2)
		{
			printf("0\n");
			continue;
		}
		else if(cnt1>cnt2)
		{
			if((cnt1-cnt2)/2<=(cnt1-zero))
				ans = (cnt1-cnt2)/2;
			else
			{
				ans = (cnt1-zero)+2*((cnt1-cnt2)/2-(cnt1-zero));
			}
		}
		else if(cnt2>cnt1)
		{
			sort(b,b+gg);
			for( i = 0 ; i < (cnt2-cnt1)/2 ; i++)
				ans+=b[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}


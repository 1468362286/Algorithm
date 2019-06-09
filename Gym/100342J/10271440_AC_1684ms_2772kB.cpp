//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

const int maxn = 1510;
bitset<maxn> s[maxn];
bitset<maxn> t[maxn];
bitset<maxn> tmp;
char ch[3000];

int main()
{
  freopen("triatrip.in","r",stdin);//必须加上，不然得WA
  freopen("triatrip.out","w",stdout);
//	freopen("in.txt","r",stdin);
	int n,i,j;


	while(scanf("%d",&n)!=EOF)
	{
		//reset()会wa
		for( i = 0 ; i < n ; i++)
		{
			scanf("%s",ch);
			for( j = 0 ; j < n ; j++)
			{
				if(ch[j]=='+')
				{
					s[i].set(j);
					t[j].set(i);
				}
			}
			getchar();
		}
		_int64 ans = 0;
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < n ; j++)
			{
				if(s[i][j])
				{
					tmp = s[j]&t[i];//必须如此
					ans+=tmp.count();
				}
			}
		}
		printf("%I64d\n",ans/3);
	}
	return 0;
}
/*耗时：2276ms，必须加freopen两个，不然会wa*/
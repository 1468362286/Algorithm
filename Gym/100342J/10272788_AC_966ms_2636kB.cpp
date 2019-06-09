//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
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
		}
		long long ans = 0;
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
		printf("%lld\n",ans/3);
	}
	return 0;
}


/*耗时：2276ms，必须加freopen两个，不然会wa
直接读字符串，耗时：1684ms,速度快很多
第二种写法优化了查询的时间，用vector存了i点的出度，遍历时就很方便，耗时:934ms
但是只能在g++中提交。用的是g++14，版本肯定有优化
*/
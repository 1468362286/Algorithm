//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

const int maxn = 1501;
bitset<maxn> p[maxn][2],tmp;
vector<int> v[maxn];
char ch[3000];

int main()
{
  freopen("triatrip.in","r",stdin);//必须加上，不然得WA
  freopen("triatrip.out","w",stdout);
	//freopen("in.txt","r",stdin);
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
					v[i].push_back(j);
					p[i][0].set(j);//i能到达的点，即i的出度
					p[j][1].set(i);//能到i的点，即i的入度
				}
			}
		}
		_int64 ans = 0;
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < v[i].size() ; j++)
			{
				tmp = p[v[i][j]][0]&p[i][1];//必须如此
				ans+=tmp.count();				
			}
		}
		printf("%I64d\n",ans/3);
	}
	return 0;
}
/*耗时：2276ms，必须加freopen两个，不然会wa
直接读字符串，耗时：1684ms,速度快很多*/
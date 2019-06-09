//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

const int maxn = 1510;
bitset<maxn> s[maxn];
bitset<maxn> t[maxn];
bitset<maxn> tmp;

int main()
{
  freopen("triatrip.in","r",stdin);//必须加上，不然得WA
  freopen("triatrip.out","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j;
	char ch;
	scanf("%d",&n);
	
		getchar();
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < n ; j++)
			{
				scanf("%c",&ch);
				if(ch=='+')
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
					tmp = s[j]&t[i];
					ans+=tmp.count();
				}
			}
		}
		printf("%I64d\n",ans/3);
	
	return 0;
}
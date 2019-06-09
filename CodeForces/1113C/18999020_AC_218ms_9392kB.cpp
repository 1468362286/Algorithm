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
const int maxn=300010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int cnt[2][(1<<20)+3];
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		memset(cnt,0,sizeof(cnt));
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		cnt[1][0]=1;
		ll res=0;
		int x = 0;
		for( i = 0 ; i < n ; i++)
		{
			x^=a[i];
			res+=cnt[i%2][x];
			++cnt[i%2][x];
		}
		printf("%I64d\n",res);
	}
	return 0;
}
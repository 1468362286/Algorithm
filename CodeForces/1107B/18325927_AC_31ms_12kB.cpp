#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int q;
	ll k,x;
	cin>>q;
	while(q--)
	{
		scanf("%I64d%I64d",&k,&x);
		x+=9*(k-1);
		printf("%I64d\n",x);
	}
	return 0;
}
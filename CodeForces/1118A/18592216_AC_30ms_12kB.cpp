#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
#include <set>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int q;
	ll n,a,b;
	cin>>q;
	while(q--)
	{
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		if(b-2*a>=0)
		{
			printf("%I64d\n",n*a);
		}
		else
		{
			printf("%I64d\n",n*a+n/2*(b-2*a));
		}
	}
	return 0;
}
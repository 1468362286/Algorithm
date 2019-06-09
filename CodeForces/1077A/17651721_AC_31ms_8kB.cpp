#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 1000010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t;
	ll a,b,k;
	cin>>t;
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&k);
		printf("%I64d\n",(a-b)*(k/2)+(k%2)*a);
	}
	return 0;
}
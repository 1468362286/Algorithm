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
const int maxn = 1000010;
const int inf = 0x7fffffff;
typedef long long ll;
const ll mod=1e9+7;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
ll a[maxn];
void init()
{
	a[1]=1;
	for(int i = 2 ; i <= 1000000 ; i++)
	{
		a[i]=(a[i-1]+i+a[i-1]*i)%mod;
	}
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int T;
	ll n;
	cin>>T;
	init();
	while(T--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<n<<endl;
			continue;
		}
		cout<<a[n]%mod<<endl;
	}
	return 0;
}		
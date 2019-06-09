#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 1010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
const ll mod = 998244353;
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,i;
	ll l=1,r=1;
	string s;
	cin>>n>>s;
	for( i = 1 ; i < n ; i++)
		if(s[i]==s[i-1])l++;
		else break;
	for( i = n-1 ; i >= 1 ; i--)
		if(s[i]==s[i-1])r++;
		else break;
	if(s[0]!=s[n-1])
		printf("%I64d\n",l+r+1);
	else printf("%I64d\n",(l+1)*(r+1)%mod);
    return 0;
}
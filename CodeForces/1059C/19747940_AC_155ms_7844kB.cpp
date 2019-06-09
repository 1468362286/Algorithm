#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 1000010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
int seq[maxn],ans[maxn];
int ptr=0;

void solve(int n,int mul)
{
	int i;
	if(n==1){ans[ptr++]=mul;return;}
	if(n==2){ans[ptr++]=mul;ans[ptr++]=mul*2;return;}
	if(n==3){ans[ptr++]=mul;ans[ptr++]=mul;ans[ptr++]=mul*3;return;}
	for( i = 0 ; i < n ; i++)if(seq[i]&1)ans[ptr++]=mul;
	for( i = 0 ; i < n/2 ; i++)seq[i]=seq[2*i+1]/2;
	solve(n/2,mul*2);
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	cin>>n;
	for( i = 0 ; i < n ; i++)seq[i]=i+1;
	solve(n,1);
	for( i = 0 ; i < n ; i++)printf("%d ",ans[i]);
	return 0;
}

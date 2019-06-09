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
const int maxn = 5010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[20];
int n;
bool dfs(int sum,int step)
{
	if(step==n)
	{
		if(sum%360==0)
			return true;
		else return false;
	}
	return dfs(sum+a[step],step+1)||dfs(sum-a[step],step+1);	
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		if(dfs(0,0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
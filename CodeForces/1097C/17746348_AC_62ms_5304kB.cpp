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
const int maxn = 500010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int cnt[maxn+1],cmt[maxn+1];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	string s;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>s;
			int sum=0,Min=0;
			for( j = 0 ; j < s.size() ; j++)
			{
				if(s[j]=='(')
					sum++;
				else sum--,Min=min(Min,sum);
			}
			if(sum<=0)
			{
				if(Min==sum)cnt[-sum]++;
			}
			else
			{
				if(Min==0)cmt[sum]++;
			}
		}
		int ans=cnt[0]/2;
		for( i = 1 ; i <= maxn ; i++)
			ans+=min(cnt[i],cmt[i]);
		cout<<ans<<endl;
	}
	return 0;
}
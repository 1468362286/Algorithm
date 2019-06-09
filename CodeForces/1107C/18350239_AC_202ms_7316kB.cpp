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
const int maxn = 200010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
int a[maxn];
vector<int>vec[maxn];
bool cmp(int a,int b){return a>b;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,k,i,j;
	string s;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		cin>>s;
		int cnt=0;
		for( i = 0 ; i < n ; i++)
		{
			vec[cnt].push_back(a[i]);
			while(i+1<n&&s[i]==s[i+1])
			{
				vec[cnt].push_back(a[i+1]);
				i++;
			}
			cnt++;
		}
		ll ans=0;
		for( i = 0 ; i < cnt ; i++)
		{
			sort(vec[i].begin(),vec[i].end(),cmp);
			for( j = 0 ; j < min(vec[i].size(),k) ; j++)
				ans+=ll(vec[i][j]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
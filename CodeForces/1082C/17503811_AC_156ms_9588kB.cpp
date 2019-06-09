#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}

int s[maxn],r[maxn];
vector<int>vec[maxn];
int ans[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>s[i]>>r[i];
			vec[s[i]].push_back(r[i]);
		}
		int maxi=0;
		for( i = 1 ; i <= m ; i++)
		{
			sort(vec[i].begin(),vec[i].end(),greater<int>());
			maxi=max(maxi,vec[i].size());
			int sum=0;
			for( j = 0 ; j < vec[i].size() ; j++)
			{
				sum+=vec[i][j];
				if(sum>=0)ans[j+1]+=sum;
				else break;
			}
		}
		int res=0;
		for( i = 1 ; i <= maxi ; i++)
		{
			res=max(res,ans[i]);
		}
		cout<<res<<endl;
	}
	return 0;
}
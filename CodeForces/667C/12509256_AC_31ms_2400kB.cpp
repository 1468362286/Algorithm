#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
using namespace std;
const int maxn = 10010;
bool dp[maxn][2];
set<string>ans;
set<string>::iterator it;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		ans.clear();
		memset(dp,0,sizeof(dp));
		int len=s.size();
		for(int i = len-1 ; i >= 5 ; i--)
		{
			if(i+2==len)
			{
				dp[i][0]=true;
				ans.insert(s.substr(i,2));
				continue;
			}
			if(i+3==len)
			{
				dp[i][1]=true;
				ans.insert(s.substr(i,3));
				continue;
			}
			if(dp[i+2][1]||(dp[i+2][0]&&s.substr(i,2)!=s.substr(i+2,2)))
			{
				dp[i][0]=true;
				ans.insert(s.substr(i,2));
			}
			if(dp[i+3][0]||(dp[i+3][1]&&s.substr(i,3)!=s.substr(i+3,3)))
			{
				dp[i][1]=true;
				ans.insert(s.substr(i,3));
			}
		}
		cout<<ans.size()<<endl;
		for(it=ans.begin();it!=ans.end();++it)
		{
			cout<<*it<<endl;
		}
	}
	return 0;
}
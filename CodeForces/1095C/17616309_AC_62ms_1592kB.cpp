#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

map<int,int>ans;
queue<int>q;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(cin>>n>>k)
	{
		for( i = 0 ; i <= 30 ; i++)
		{
			if(n&(1<<i))
			{
				if(i>0)q.push(1<<i);
				ans[1<<i]++;
			}
		}
		if(int(ans.size())>k)
		{
			puts("NO");
			continue;
		}
		int cnt=ans.size();
		while(cnt<k&&!q.empty())
		{
			int z=q.front();
			q.pop();
			ans[z]--;
			ans[z/2]+=2;
			if(z/2>1)
			{
				q.push(z/2);
				q.push(z/2);
			}
			cnt++;
		}
		if(cnt<k)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		map<int,int>::iterator it;
		for( it = ans.begin() ; it!=ans.end() ; it++)
		{
			for( i = 0 ; i < (*it).second ; i++)
			{
				printf("%d ",(*it).first);
			}
		}
		puts("");
	}
	return 0;
}
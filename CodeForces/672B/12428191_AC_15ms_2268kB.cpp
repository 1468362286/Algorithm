#include <iostream>
#include <string>
using namespace std;
int vis[300];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,cnt;
	string s;
	while(cin>>n)
	{
		cin>>s;
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(!vis[s[i]])
			{
				cnt++;
				vis[s[i]]=1;
			}
		}
		if(n-cnt>26-cnt)
			printf("-1\n");
		else
		printf("%d\n",n-cnt);
	}
	return 0;
}
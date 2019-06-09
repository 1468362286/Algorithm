#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		int ans = 1e6;
		for(int i = 'a'; i <= 'z'; i++)
		{
			int k = 0,t=0;
			for(int j = 0 ; j < s.size(); j++)
			{
				if(s[j]==i)
					t = 0;
				else
					t++;
				k = max(t,k);
			}
			ans=min(k,ans);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
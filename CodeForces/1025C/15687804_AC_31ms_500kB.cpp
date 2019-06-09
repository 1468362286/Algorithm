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
		string tmp=s+s;
		int cnt=0,ans=0;
		for(int i = 1 ; i < tmp.size() ; i++)
		{
			if(tmp[i]!=tmp[i-1])
			{
				cnt++;
			}
			else
			{
				ans=max(ans,cnt);
				cnt=0;
			}
		}
		ans=max(ans,cnt);
		cout<<min(s.size(),ans+1)<<endl;
	}
	return 0;
}
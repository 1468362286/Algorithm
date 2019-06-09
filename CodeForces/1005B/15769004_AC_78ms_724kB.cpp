#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){return a>b?b:a;}
int main()
{
	string s,t;
	while(cin>>s>>t)
	{
		int len = min(s.size(),t.size());
		int ans=0;
		for(int i = 0 ; i < len ; i++)
		{
			if(s[s.size()-1-i]==t[t.size()-1-i])
				ans++;
			else
				break;
		}
		cout<<s.size()+t.size()-2*ans<<endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;


int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i;
	string s;
	while(cin>>s)
	{
		int n = s.size();
		int l = 0,r=n-1;
		int cnt=0;
		string ans="";
		if(n&1)
		{
			while(l<=r)
			{
				if(cnt&1)
				ans+=s[r--];
				else ans+=s[l++];
				cnt++;
			}
		}
		else
		{
			while(l<=r)
			{
				if(cnt&1)
				ans+=s[l++];
				else ans+=s[r--];
				cnt++;
			}	
		}
		for( i = ans.size()-1 ; i >= 0 ; i--)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
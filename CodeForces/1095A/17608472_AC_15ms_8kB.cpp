#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int cnt=0;
		string ans="";
		for( i = 0 ; i < n ; )
		{
			ans+=s[i];
			cnt++;
			i=i+cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
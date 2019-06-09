#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		int cnt=0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='-')
				cnt++;
		}
		int k = s.size()-cnt;
		if(k==0||cnt%k==0)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
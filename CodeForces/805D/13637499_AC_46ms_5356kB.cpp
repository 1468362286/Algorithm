#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int mod = 1e9+7;
int main()
{
	string s;
	while(cin>>s)
	{
		int len = s.size();
		ll ans = 0;
		ll cnt = 0;
		for(int i = len-1 ; i >= 0 ; i--)
		{
			if(s[i]=='b')
			{
				cnt++;
			}
			else if(s[i]=='a')
			{
				ans = (ans+cnt)%mod;
				cnt = (cnt*2)%mod;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
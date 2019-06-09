#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
const int mod = 1000000007;
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int i;
	while(cin>>s)
	{
		string S="";
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='a')
			{
				S+=s[i];
			}
			else if(s[i]=='b'&&(S[S.size()-1]=='a'))
			{
				S+=s[i];
			}
		}
		S+='b';
		ll ans=1;
		ll cnt=0;
		for( i = 0 ; i < S.size() ; i++)
		{
			if(S[i]=='a')
			{
				cnt++;
			}
			else
			{
				ans=(ans*(cnt+1))%mod;
				cnt=0;
			}
		}
		printf("%I64d\n",ans-1);
	}
	return 0;
}
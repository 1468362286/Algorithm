#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int mod = 1000000000+7;

int change(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else if(c>='A'&&c<='Z')
		return c-'A'+10;
	else if(c>='a'&&c<='z')
		return c-'a'+36;
	else if(c=='-')
		return 62;
	else if(c=='_')
		return 63;
}
_int64 Pow(_int64 a,_int64 k)
{
	_int64 ans = 1;
	while(k)
	{
		if(k%2==0)
		{
			a=(a*a)%mod;
		}
		else
		{
			ans=(ans*a)%mod;
			a=(a*a)%mod;
		}
		k>>=1;
	}
	return ans;
}
_int64 Pow1(_int64 a,_int64 k)
{
	_int64 sum = 1;
	while(k)
	{
		if(k&1)
			sum=(sum*a)%mod;
		a=(a*a)%mod;
		k>>=1;
	}
	return sum;
}
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		_int64 ans = 1;
		for(int i = 0 ; i < s.size() ; i++)
		{
			int tmp = change(s[i]);
			_int64 cnt = 0;
			for(int j = 0 ; j < 6 ; j++)
			{
				if(!((tmp>>j)&1))
					cnt++;
			}
			ans=((ans*Pow(3,cnt))%mod);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
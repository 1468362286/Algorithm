#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	int n,i;
	ll x,y;
	string s;
	while(~scanf("%d%I64d%I64d",&n,&x,&y))
	{
		cin>>s;
		ll ans=0;
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]=='0')
			{
				ans++;
				while(s[i+1]=='0')
					i++;
			}
		}
		if(ans==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(x<=y)
			printf("%I64d\n",(ans-1)*x+y);
		else
			printf("%I64d\n",ans*y);
	}
	return 0;
}

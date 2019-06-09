#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
string s1 = " What are you doing at the end of the world? Are you busy? Will you save us?";
string s2 = " What are you doing while sending \"";
string s3 = " \"? Are you busy? Will you send \"";
string s4 = " \"?";
int la = 75,lb=34,lc=32,ld=2;

ll len(ll i)
{
	ll a = 1;
	ll b = 54;
	ll c = 9000000000000000000;
	if(i>b)return c;
	return ((a<<i)-a)*(la+lb+lc+ld)+la;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int q;
	ll n,k;
	while(~scanf("%d",&q))
	{
		string s;
		while(q--)
		{
			scanf("%I64d%I64d",&n,&k);

			ll temp = len(n-1);
			if(k>len(n))
			{
				s+=".";
				continue;
			}
			ll form = 1;
			for( ll i = n ; i >=1 ; i--)
			{
				ll temp = len(i-1);
				bool flag = false;
				if(k>=1&&k<=lb)
				{
					form = 2;
					flag = true;
				}
				if(k>(lb+temp)&&k<=(lb+temp+lc))
				{
					form = 3;
					k-=lb+temp;
					flag = true;
				}
				if(k>(lb+temp*2+lc)&&k<=(lb+temp*2+lc+ld))
				{
					form = 4;
					k-=lb+temp*2+lc;
					flag = true;
				}
				if(flag) break;
				if( k>lb&&k<=(lb+temp))
				{
					k-=lb;
				}
				if(k>(lb+temp+lc)&&k<=(lb+temp*2+lc))
				{
					k-=lb+temp+lc;
				}
			}
			if(form==1)s+=s1[k];
			if(form==2)s+=s2[k];
			if(form==3)s+=s3[k];
			if(form==4)s+=s4[k];
					
		}		
cout<<s<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,T,i,x;
	cin>>T;
	int cases=0;
	while(T--)
	{
		cases++;
		cin>>n;
		int cnt=0;
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x>0)
			{
				cnt++;
			}
			ans+=abs(x);
		}
		if(cnt==0)
			printf("Case %d: inf\n",cases);
		else
		{
			x = gcd(cnt,ans);
			printf("Case %d: %d/%d\n",cases,ans/x,cnt/x);
		}
	}
	return 0;
}
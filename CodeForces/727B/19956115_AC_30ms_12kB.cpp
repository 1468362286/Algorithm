#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 500010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}

bool isdig(char c)
{
	if(c>='0'&&c<='9')
		return true;
	else
		return false;
}
bool isletter(char c)
{
	if(c>='a'&&c<='z')
	{
		return true;
	}
	else
		return false;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	int i,z;
	ll f;
	while(cin>>s)
	{
		double tmp=0;
		double ans=0;
		int flag=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(isletter(s[i]))
			{
				if(flag)
				{
					tmp/=100;
					flag=0;
				}
				if(tmp!=0)ans+=tmp;
				tmp=0;
			}
			else if(isdig(s[i])||s[i]=='.')
			{
				if(isdig(s[i]))
				{
					tmp=tmp*10+(s[i]-'0');
				}
				else
				{
					if(i+3>=s.size()||isletter(s[i+3]))
					{
						flag=1;
					}
				}
			}
		}
		if(tmp!=0)
		{
			if(flag)tmp/=100;
			ans+=tmp;
		}
		z = int(ans);
		double gg=ans-z;
		f=int(gg*100+0.1);
	//	f = ll(ans*100)%100;
		vector<int>vec;
		vec.clear();
		if(z==0)vec.push_back(0);
		while(z)
		{
			vec.push_back(z%10);
			z/=10;
		}
		int cnt=0;
		int x = vec.size()%3;
		if(x!=0)
		{
			int len=vec.size()-x;
			for( i = vec.size()-1 ; i >= len ; i--)
				cout<<vec[i];
		}
		if(x!=0&&vec.size()/3>0)cout<<".";
		for( i = vec.size()-1-x ; i >= 0 ; i--)
		{
			cnt++;
			cout<<vec[i];
			if(cnt==3&&i!=0)cout<<".";
		}
		if(f!=0)
		{
			int last = f%10;
			f/=10;
			int first = f%10;
			cout<<"."<<first<<last;
		}
		cout<<endl;
	}
	return 0;
}
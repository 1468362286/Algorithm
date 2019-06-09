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
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
multiset<ll>myset;
map<string,int>mymap;
bool match(ll x,string s)
{
	int i;
	vector<int>vec;
	int cnt=0;
	while(x)
	{
		vec.push_back(x%10);
		x/=10;
		cnt++;
	}
//	reverse(vec.begin(),vec.end());
//	reverse(s.begin(),s.end());
	if(cnt>s.size())
	{
		int len = cnt-s.size();
		string tmp="";
		for( i = 0 ; i < len ; i++)
			tmp+='0';
		tmp+=s;
		s=tmp;
	}
	else if(cnt<s.size())
	{
		int len = s.size()-cnt;
		for( i = 0 ; i < len ; i++)
			vec.push_back(0);

	}
	reverse(vec.begin(),vec.end());
	cnt=0;
	for( i = 0 ; i < vec.size() ; i++)
	{
	//	cout<<vec[i]<<" "<<s[i]<<endl;
		if(((vec[i]&1)&&(s[i]-'0'))||((!(vec[i]&1))&&!(s[i]-'0')))
			cnt++;
	}
	if(cnt==vec.size())
		return true;
	else return false;
}

string change(ll x)
{
	int i;
	vector<int>vec;
	while(x)
	{
		vec.push_back(x%10);
		x/=10;
	}
	reverse(vec.begin(),vec.end());
	string ans="";
	for( i = 0 ; i < vec.size() ; i++)
	{
		if(vec[i]&1)
		{
			ans+='1';
		}
		else
			ans+='0';
	}
	string tmp="";
	for( i = 0 ; i < 18-ans.size() ; i++)
		tmp+='0';
	tmp+=ans;
	return tmp;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,i;
	ll x;
	string opt,s;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>opt;
			if(opt[0]=='+')
			{
				scanf("%I64d",&x);
				myset.insert(x);
				mymap[change(x)]++;
			}
			else if(opt[0]=='-')
			{
				scanf("%I64d",&x);
				multiset<ll>::iterator pos=myset.find(x);
				myset.erase(pos);
				mymap[change(x)]--;
			}
			else
			{
				cin>>s;
				string tmp="";
				for( i = 0 ; i < 18-s.size() ; i++)
					tmp+='0';
				tmp+=s;
				cout<<mymap[tmp]<<endl;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int c[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	string s;
	int i,x;
	while(cin>>s)
	{
		string tmp="";
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]!='a')
				tmp+=s[i];
		}
		if(tmp.size()==0)
		{
			cout<<s<<endl;
			continue;
		}
		string s1=tmp.substr(0,tmp.size()/2);
		string s2=tmp.substr(tmp.size()/2,tmp.size()-1);
		if(tmp.size()%2==0&&tmp.substr(0,tmp.size()/2)==tmp.substr(tmp.size()/2,tmp.size()-1))
		{
			x=0;
			int an=0;
			while((x=s.find(tmp.substr(0,tmp.size()/2),x))!=string::npos)
			{
				an=x;
				x++;
			}
		//		x = s.find(tmp.substr(0,tmp.size()/2));
			if(x==0)x++;
			string ans=s.substr(0,an);
			string t="";
			for( i = 0 ; i < ans.size() ; i++)
				if(ans[i]!='a')t+=ans[i];
			string T=ans+t;
			if(s==T)
			{
				cout<<ans<<endl;
			}
			else
				cout<<":("<<endl;
		}
		else
			cout<<":("<<endl;
	}
	return 0;
}		
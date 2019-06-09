#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <utility>
using namespace std;
const int maxn=300010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	string s;
	int k,i,j,tmp;
	while(cin>>s>>k)
	{
		int cnt=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='?'||s[i]=='*')
				cnt++;
		}
		string ans="";
		if(s.size()-cnt>k)
		{
			tmp=(s.size()-cnt)-k;
			for( i = 0 ; i < s.size() ; i++)
			{
				if((s[i+1]=='*'||s[i+1]=='?')&&tmp)
				{
					tmp--;
				}
				else if(s[i]!='*'&&s[i]!='?')
					ans+=s[i];
			}
		}
		else
		{
			tmp=k-(s.size()-cnt);
			for( i = 0 ; i < s.size() ; i++)
			{
				if(s[i+1]=='*'&&tmp)
				{
					for( j = 0 ; j <= tmp ; j++)
						ans+=s[i];
					tmp=0;
				}
				else if(s[i]!='*'&&s[i]!='?')
					ans+=s[i];
			}
		}
		if(ans.size()==k) cout<<ans<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
char ch[4]="RGB";
vector<pair<char,int> >vec;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	string s,Ans;
	while(cin>>n)
	{
		cin>>s;
		vec.clear();
		int cnt=1;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i+1]==s[i])
			{
				cnt++;
			}
			else
			{
				vec.push_back(make_pair(s[i],cnt));
				cnt=1;
			}
		}
		Ans="";
		int ans=0;
		char k;
		for( i = 0 ; i < vec.size() ; i++)
		{
			char c = vec[i].first;
			int x = vec[i].second;
			char tmp;
			if(i+1<vec.size())
				k = vec[i+1].first;
			else
				k=c;
			for( j = 0 ; j < 3 ; j++)
				if(ch[j]!=c&&ch[j]!=k)
				{
					tmp = ch[j];
					break;
				}
			for( j = 0 ; j < x ; j++)
				if(j%2==0)Ans+=c;
				else Ans+=tmp;
			ans+=(x)/2;
		}
		cout<<ans<<endl;
		cout<<Ans<<endl;
	}
	return 0;
}
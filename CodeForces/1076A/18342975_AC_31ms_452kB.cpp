#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int ans=-1;
		for( i = 1 ; i < s.size() ; i++)
		{
			if(s[i]<s[i-1])
			{
				ans=i-1;
				break;
			}
		}
		if(ans==-1)
		{
			for( i = 0 ; i < s.size()-1 ; i++)
				cout<<s[i];
			cout<<endl;
			continue;
		}
		for( i = 0 ; i < s.size() ; i++)
			if(i!=ans)cout<<s[i];
		cout<<endl;
	}
	return 0;
}
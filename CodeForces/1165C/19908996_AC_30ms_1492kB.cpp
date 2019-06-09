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
const int maxn = 200010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int a[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	string s;
	while(cin>>n>>s)
	{
		string ans="";
		for( i = 0 ; i < n-1 ; i++)
		{
			if(s[i+1]!=s[i])
			{
				ans+=s[i];
				ans+=s[i+1];
				i++;
			}
		}
		cout<<s.size()-ans.size()<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
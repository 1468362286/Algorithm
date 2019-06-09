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
const int maxn = 3010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
map<char,int>mymap;

int jie(int x)
{
	if(x==1||x==0)return 0;
	x--;
	return (1+x)*x/2;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n;
	int ans,i;
	string s;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>s;
			mymap[s[0]]++;
		}
		int ans=0; 
		for( i = 0 ; i < 26 ; i++)
		{
			char c='a'+i;
			int tmp1 = mymap[c]/2;
			int tmp2 = mymap[c]-tmp1;
			ans+=jie(tmp1)+jie(tmp2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
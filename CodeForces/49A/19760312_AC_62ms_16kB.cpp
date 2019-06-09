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
const int maxn = 10010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
char ch[]={'A','a','E','e','I','i','O','o','U','u','Y','y'};
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	int i;
	getline(cin,s);
	int flag=0;
	int tmp=0;
	for( i = s.size()-1 ; i >= 0 ; i--)
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			tmp=i;
			break;
		}
	for( i = 0 ; i < 12 ; i++)
	if(s[tmp]==ch[i])
	{
		flag=1;
		break;
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

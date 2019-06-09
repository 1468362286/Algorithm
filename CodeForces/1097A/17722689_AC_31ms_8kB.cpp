#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 5010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s,tmp;
	int i;
	while(cin>>s)
	{
		string tmp;
		vector<string>v;
		for( i = 0 ; i < 5 ; i++)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		int flag=0;
		for( i = 0 ; i < 5 ; i++)
		{
			if(v[i].find(s[0])!=v[i].npos||v[i].find(s[1])!=v[i].npos)
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

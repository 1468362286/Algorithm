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
		string ans="";
		int cnt=0;
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]=='(')
			{
				cnt++;
				if(cnt&1)
					cout<<0;
				else
					cout<<1;
			}
			else
			{
				if(cnt&1)
					cout<<0;
				else
					cout<<1;
				cnt--;
			}
		}
		cout<<endl;
	}
	return 0;
}
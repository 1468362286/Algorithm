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

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,x,y,i;
	string s;
	while(cin>>n>>x>>y)
	{
		int cnt=0;
		cin>>s;
		for( i = s.size()-1 ; i > s.size()-1-x ; i--)
		{
			if(s[i]=='1')
				cnt++;
		}
		if(s[s.size()-1-y]=='1')
			cnt--;
		else
			cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
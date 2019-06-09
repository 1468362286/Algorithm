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
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
int w[]={52,52,52,52,53,53,52,52};
int v[]={31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string a,b;
	int x,i;
	while(cin>>x)
	{
		cin>>a>>b;
		if(b[0]=='w')
		{
			cout<<w[x-1]<<endl;	
		}
		else if(b[0]=='m')
		{
			int cnt=0;
			for( i = 0 ; i < 12 ; i++)
				if(v[i]>=x)
					cnt++;
			cout<<cnt<<endl;
		}
	}
	return 0;
}
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


int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,x;
	while(cin>>n)
	{
		int flag=0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x==1)flag=1;
		}
		if(flag)cout<<"HARD"<<endl;
		else cout<<"EASY"<<endl;
	}
	return 0;
}
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
int a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,s,t,i;
	while(cin>>n>>s>>t)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int pos=s;
		int cnt=0;
		while(1)
		{
			if(pos==t)break;
			pos=a[pos];
			cnt++;
			if(cnt>n)break;
		}
		if(cnt<n)
		{
			cout<<cnt<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}
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

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,n,i;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int pos=-1;
		for( i = 0 ; i < n ; i++)
			if(s[i]=='8')
			{
				pos=i;
				break;
			}
		if(pos!=-1&&n-pos>=11)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
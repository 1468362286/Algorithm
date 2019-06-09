#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m;
	while(cin>>n>>m)
	{
		if(m%n!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		int tmp = m/n;
		int ans=0;
		while(tmp%2==0)
		{
			tmp/=2;
			ans++;
		}
		while(tmp%3==0)
		{
			tmp/=3;
			ans++;
		}
		if(tmp==1)
			cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
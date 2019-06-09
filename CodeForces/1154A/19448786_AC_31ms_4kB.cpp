#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 150010;
const int inf = 0x7fffffff;
typedef long long ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	ll a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		ll sum=(a+b+c+d)/3;
		if(a!=sum)
			cout<<sum-a<<" ";
		if(b!=sum)
			cout<<sum-b<<" ";
		if(c!=sum)
			cout<<sum-c<<" ";
		if(d!=sum)
			cout<<sum-d<<" ";
		cout<<endl;
	}
	return 0;
}		
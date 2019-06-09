#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <utility>
using namespace std;
const int maxn=300010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,res;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<2<<endl;
			continue;
		}
		int p = sqrt(double(n));
		if(p*p==n)
		{
			res=2*p;
		}
		else if(p*(p+1)>=n)
			res=2*p+1;
		else
			res=2*(p+1);
		cout<<res<<endl;
	}
	return 0;
}
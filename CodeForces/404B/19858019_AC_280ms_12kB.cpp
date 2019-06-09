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
const int maxn = 1010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	double a,d;
	while(cin>>a>>d>>n)
	{
		for( i = 1 ; i <= n ; i++)
		{
			double tmp = i*d;
			ll k = ll(tmp/a);
			double dis = tmp- k*a;
			k%=4;
			if(k==0)
			{
				printf("%.10lf %.10lf\n",dis,0);
			}
			else if(k==1)
			{
				printf("%.10lf %.10lf\n",a,dis);
			}
			else if(k==2)
			{
				printf("%.10lf %.10lf\n",a-dis,a);
			}
			else if(k==3)
			{
				printf("%.10lf ",0);
				printf("%.10lf\n",a-dis);
			}
		}
	}
	return 0;
}
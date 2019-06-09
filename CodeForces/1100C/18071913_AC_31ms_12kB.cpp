#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
#include <math.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const ll mod = 1000000007;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
const int maxn=100010;
const double pi = acos(-1.0);
//int a[maxn];

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n;
	double R,r;
	while(cin>>n>>r)
	{
		double a=pi*(n-2)/n;
		R = r*cos(a/2)/(1-cos(a/2));
		printf("%.6lf\n",R);
	}
    return 0;
}
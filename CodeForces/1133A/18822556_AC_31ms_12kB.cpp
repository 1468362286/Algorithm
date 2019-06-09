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
ll min(ll a,ll b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int h1,m1,h2,m2;
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	int s1 = h1*60+m1;
	int s2 = h2*60+m2;
	int s = s2-s1;
	s/=2;
	s+=s1;
	printf("%02d:%02d\n",s/60,s%60);
	return 0;
}
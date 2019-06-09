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
const int maxn=100010;
const int inf = 0x7fffffff;
typedef _int64 ll;

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int x,y,z,t1,t2,t3;
	while(cin>>x>>y>>z>>t1>>t2>>t3)
	{
		if(abs(z-x)*t2+3*t3+abs(x-y)*t2>abs(x-y)*t1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}	
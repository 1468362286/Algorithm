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
	ll b;
	while(~scanf("%I64d",&b))
	{
		int cnt=2;
		if(b==1)cnt--;
		for(ll i = 2 ; i <= sqrt(double(b)) ; i++)
		{
			if(b%i==0)
			{
				if(i*i==b)
					cnt++;
				else
					cnt+=2;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}	
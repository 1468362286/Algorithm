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
const int maxn=200010;
typedef _int64 ll;

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,v;
	while(cin>>n>>v)
	{
		int V=0;
		int ans=0;
		for(int i = 1 ; i <= n ; i++)
		{
			if(V<v)
			{
				if(n-i<=v)
				{
					ans+=(n-i-V)*i;
					break;
				}
				else
				{
					ans+=(v-V)*i;
					V=v;
				}
			}
			V--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
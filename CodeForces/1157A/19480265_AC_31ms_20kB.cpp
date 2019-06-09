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
const int maxn = 1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
map<int,int>mymap;
int f(int x)
{
	x++;
	while(x%10==0)
		x/=10;
	return x;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		int tmp=n;
		mymap.clear();
		mymap[tmp]++;
		for( i = 1 ; ; i++)
		{
			if(mymap.find(f(tmp))!=mymap.end())
				break;
			mymap[f(tmp)]++;
			tmp=f(tmp);
		}
		cout<<mymap.size()<<endl;
	}
	return 0;
}		
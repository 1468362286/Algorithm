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
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
map<int,int>mymap;
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,x;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 1 ; i <= n ; i++)
			cin>>a[i],mymap[a[i]]++;
		map<int,int>::iterator it;
		int maxi = 0;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			if((*it).second>maxi)
			{
				maxi = (*it).second;
				x = (*it).first;
			}
		}
		cout<<n-mymap[x]<<endl;
		int pos=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(a[i]==x)
			{
				pos=i;
				break;
			}
		}
		for( i = pos-1 ; i >= 1 ; i--)
		{
			if(a[i]>x)
			{
				cout<<2<<" "<<i<<" "<<i+1<<endl;
			}
			else if(a[i]<x)
			{
				cout<<1<<" "<<i<<" "<<i+1<<endl;
			}
		}
		for( i = pos+1 ; i <= n ; i++)
		{
			if(a[i]>x)
			{
				cout<<2<<" "<<i<<" "<<i-1<<endl;
			}
			else if(a[i]<x)
			{
				cout<<1<<" "<<i<<" "<<i-1<<endl;
			}
		}
	}
	return 0;
}	
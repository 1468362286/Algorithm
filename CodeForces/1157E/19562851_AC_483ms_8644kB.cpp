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
const int maxn = 200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
multiset<int>myset;
int a[maxn],b[maxn],c[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i],myset.insert(b[i]);
		for( i = 0 ; i < n ; i++)
		{
			multiset<int>::iterator it;
			it = myset.lower_bound(n-a[i]);
			if(it!=myset.end())
			{
				if(((*it)+a[i])%n<(*myset.begin()+a[i])%n)
				{
					c[i]=((*it)+a[i])%n;
					myset.erase(it);
				}
				else
				{
					c[i]=(*myset.begin()+a[i])%n;
					myset.erase(myset.begin());
				}
			}
			else
			{
				c[i]=(*myset.begin()+a[i])%n;
				myset.erase(myset.begin());
			}
		}
		for( i = 0 ; i < n ; i++)
			cout<<c[i]<<" ";
		cout<<endl;
	}
	return 0;
}		
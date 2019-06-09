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
const int maxn=1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int la[maxn],ra[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,l,r,L,R;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>la[i];
		for( i = 1 ; i <= n ; i++)
			cin>>ra[i];
		for( i = 1 ; i <= n ; i++)
			a[i]=n-la[i]-ra[i];
		int flag=0;
		for( i = 1 ; i <= n ; i++)
		{
			L=0,R=0;
			for(l = 1 ; l < i ; l++)
			{
				if(a[l]>a[i])
					L++;
			}
			for(r = i+1 ; r <= n ; r++)
			{
				if(a[r]>a[i])
					R++;
			}
			if(L!=la[i]||R!=ra[i])
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for( i = 1 ; i <= n ; i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}	
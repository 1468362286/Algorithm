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
int a[maxn];
ll sum(int u)
{
	return ll(1)*u*(u+1)/2;
}

double sumb(int u)
{
	return pow(2.0,u)-1;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,k,i;
	while(cin>>n>>k)
	{
		for( i = 1 ; i <= k ; i++)
		{
			int rep=max(a[i-1]+1,(int)ceil((double)n/sumb(k+1-i)));
			if(sum(rep+k-i)-sum(rep-1)>n)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			a[i]=rep;
			n-=rep;
		}
		cout<<"YES"<<endl;
		for( i = 1 ; i <= k ; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}		
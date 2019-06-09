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
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		int l=0,r=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			if(a[i])l++;
			else r++;
		}
		for( i = 0 ; i < n ; i++)
		{
			if(a[i])l--;
			else r--;
			if(l==0||r==0)
				break;
		}
		cout<<i+1<<endl;
	}
	return 0;
}	
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 1000010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,k,i;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < k ; i++)
			cout<<n-i<<" ";
		for( i = 1 ; i <= n-k ; i++)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
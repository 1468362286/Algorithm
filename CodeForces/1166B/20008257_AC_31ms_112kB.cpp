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
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
char table[]="aeiou";
char ans[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	while(cin>>n)
	{
		int x=-1,y=-1;
		for( i = 5 ; i*i<= n ; i++)
		{
			if(n%i==0)
			{
				if(i>=5&&n/i>=5)
				{
					x=i,y=n/i;
					break;
				}
			}
		}
		if(x<0||y<0)
		{
			puts("-1");
			continue;
		}
		for( i = 0 ; i < x ; i++)
			for( j = 0 ; j < y ; j++)
			{
				ans[i*y+j]=table[(i+j)%5];
			}
		for( i = 0 ; i < x ; i++)
			for( j = 0 ; j < y ; j++)
				cout<<ans[i*y+j];
		cout<<endl;
	}
	return 0;
}
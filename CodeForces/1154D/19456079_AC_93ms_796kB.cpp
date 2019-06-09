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
int c[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,a,b;
	while(cin>>n>>b>>a)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>c[i];
		}
		int B=b,A=a;
		for( i = 1 ; i <= n ; i++)
		{
			if(c[i])
			{
				if(A<a&&B>0)
				{
					B--;
					A++;
				}
				else
				{
					if(A>0)
						A--;
					else
						B--;	
				}
			}
			else
			{
				if(A>0)
					A--;
				else
					B--;
			}
			if(A==0&&B==0)
				break;
		}
		cout<<min(i,n)<<endl;
	}
	return 0;
}		
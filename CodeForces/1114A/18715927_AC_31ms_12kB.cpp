#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <utility>
using namespace std;
const int maxn=300010;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int x,y,z,a,b,c;
	while(cin>>x>>y>>z>>a>>b>>c)
	{
		a-=x;
		if(a>=0&&a+b>=y&&a+b-y+c>=z)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
			
	}
	return 0;
}
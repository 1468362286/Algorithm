#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,x,y,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y>>d;	
		if(abs(y-x)%d==0)
			cout<<abs(y-x)/d<<endl;
		else
		{
			int flag=0;
			int tmp = (x-1)/d+((x-1)%d==0?0:1);
			if((y-1)%d==0)
				tmp+=(y-1)/d,flag=1;
			else
				tmp=inf;
			int tm=(n-x)/d+((n-x)%d==0?0:1);
			if((n-y)%d==0)
				tm+=(n-y)/d,flag=1;
			else
				tm=inf;
			if(flag)
				cout<<min(tmp,tm)<<endl;
			else
				cout<<"-1"<<endl;
		}
	}
	return 0;
}
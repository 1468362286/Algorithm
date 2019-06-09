#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string s;
int e,b,n,c;
int max(int a,int b){return a>b?a:b;}
void dfs(int x,int y,int z)
{
	b=s[x]-'0';
	if(x==n-1)
	{
		c=sqrt(y);
		if(c*c==y&&y!=0)
			e=max(e,z);
		y=y*10+b;
		c=sqrt(y);
		if(c*c==y&&y!=0)
			e=max(e,z+1);
		return;
	}
	if(b!=0||y!=0)
		dfs(x+1,y*10+b,z+1);
	dfs(x+1,y,z);
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>s)
	{
		e=-1;
		n=s.size();
		dfs(0,0,0);
		if(e==-1)
			printf("-1\n");
		else
			printf("%d\n",n-e);
	}
	return 0;
}
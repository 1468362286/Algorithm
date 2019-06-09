#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200005;
struct seg
{
	int x1,x2;
}s[maxn];
int n,h,m[maxn];
vector<int>d;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,l;
	scanf("%d%d%d%d",&n,&h,&s[0].x1,&s[0].x2);
	m[0]=0;d.push_back(0);
	for( i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&s[i].x1,&s[i].x2);
		d.push_back(s[i].x1-s[i-1].x2+d[i-1]);
		m[i]=s[i-1].x2-s[i-1].x1+m[i-1];
	}
	m[n]=s[n-1].x2-s[n-1].x1+m[n-1];
	int ans=0;
	for( l = 0 ; l < n ; l++)
	{
		int r = upper_bound(d.begin(),d.end(),h+d[l])-d.begin()-1;
		if(d[r]-d[l]<h)
		{
			ans=max(ans,h+m[r+1]-m[l]);
		}
		if(d[r]-d[l]==h)
		{
			ans=max(ans,max(s[r].x1-s[l].x1,s[r].x2-s[l].x2));
		}
	}
	cout<<ans<<endl;
	return 0;
}
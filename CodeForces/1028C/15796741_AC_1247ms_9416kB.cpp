#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 200000;
const int inf = 0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct node
{
	int lx,ly,rx,ry;
	node(){};
	node(int _lx,int _ly,int _rx,int _ry)
	{
		lx=_lx,ly=_ly,rx=_rx,ry=_ry;
	}
}q[maxn],pre[maxn],suf[maxn];

bool judge(node a)
{
	if(a.lx>a.rx||a.ly>a.ry)
		return false;
	return true;
}
int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>q[i].lx>>q[i].ly>>q[i].rx>>q[i].ry;
		}
		pre[0].lx=pre[0].ly=-inf;
		pre[0].rx=pre[0].ry=inf;
		for( i = 1 ; i <= n ; i++)
		{
			pre[i].lx=max(pre[i-1].lx,q[i].lx);
			pre[i].ly=max(pre[i-1].ly,q[i].ly);
			pre[i].rx=min(pre[i-1].rx,q[i].rx);
			pre[i].ry=min(pre[i-1].ry,q[i].ry);
		}
		suf[n+1].lx=suf[n+1].ly=-inf;
		suf[n+1].rx=suf[n+1].ry=inf;
		for( i = n ; i >= 1 ; i--)
		{
			suf[i].lx=max(suf[i+1].lx,q[i].lx);
			suf[i].ly=max(suf[i+1].ly,q[i].ly);
			suf[i].rx=min(suf[i+1].rx,q[i].rx);
			suf[i].ry=min(suf[i+1].ry,q[i].ry);
		}
		for( i = 1 ; i <= n ; i++)
		{
			int tmplx = max(pre[i-1].lx,suf[i+1].lx);
			int tmply = max(pre[i-1].ly,suf[i+1].ly);
			int tmprx = min(pre[i-1].rx,suf[i+1].rx);
			int tmpry = min(pre[i-1].ry,suf[i+1].ry);
			if(judge(node(tmplx,tmply,tmprx,tmpry)))
			{
				cout<<tmplx<<" "<<tmply<<endl;
				return 0;
			}
		}
	}
	return 0;
}
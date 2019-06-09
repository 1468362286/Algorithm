#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;
inline double max(double a,double b){return a>b?a:b;}
inline double min(double a,double b){return a>b?b:a;}
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

struct node
{
	int x,y;
	double z;
	friend bool operator<(const node &a,const node &b)
	{
		return a.z<b.z;
	}
	node(int x,int y,double z):x(x),y(y),z(z){}
	node(){};
};

int n,m,r,k;
double ans=0;
priority_queue<node> q;
map<pair<int,int>,int > mp;

inline bool check(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m&&mp.count(make_pair(x,y))==0;
}

inline double solve(int x,int y)
{
	/*
	double x1=min(1.00*x,n-x+1.00);
	x1=min(x1,n-1.00*r+1);
	x1=min(x1,1.00*r);
	double y1=min(1.00*y,m-y+1.00);
	y1=min(y1,m-1.00*r+1);
	y1=min(y1,1.00*r);
	*/
	double x1=min(n+1.0,x+r*1.0)-max(x*1.0,r*1.0);
	double y1=min(m+1.0,y+r*1.0)-max(y*1.0,r*1.0);
	return x1*y1/1.00/(n-r+1)/(m-r+1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n>>m>>r>>k)
	{
		while(!q.empty()) q.pop();
		mp.clear();
		q.push(node(r,r,solve(r,r)));
		mp[make_pair(r,r)]=1;
		while(k--)
		{
			node now = q.top();
			int x=now.x,y=now.y;
			double z=now.z;
			ans+=z;
			q.pop();
			for(int i = 0 ; i < 4 ; i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(check(nx,ny))
				{
					mp[make_pair(nx,ny)]=1;
					q.push(node(nx,ny,solve(nx,ny)));
				}
			}
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}
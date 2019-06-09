#include <iostream>
#include <string>
#define N 100005
using namespace std;

int n,m,d[N],sd[N][3],f[2*N];

int Find(int x){return f[x]==x?x:f[x]=Find(f[x]);}

void link(int a,int b)
{
	int x = Find(a),y=Find(b);
	if(x!=y)f[x]=y;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	cin>>n>>m;
	for( i = 0 ; i < n ;i++)
		cin>>d[i];
	for( i = 0 ; i < m ; i++)
	{
		int x;
		cin>>x;
		for( j = 0 ; j < x ; j++)
		{
			int dr;
			cin>>dr,dr--;
			sd[dr][++sd[dr][0]]=i;
		}
	}
	for( i = 0 ; i < 2*m ; i++)
		f[i]=i;
	for( i = 0 ; i < n ; i++)
	{
		if(d[i])
			link(sd[i][1],sd[i][2]),link(sd[i][1]+m,sd[i][2]+m);
		else
			link(sd[i][1],sd[i][2]+m),link(sd[i][1]+m,sd[i][2]);
	}
	for( i = 0 ; i < m ; i++)
		if(Find(i)==Find(i+m))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	return 0;
}
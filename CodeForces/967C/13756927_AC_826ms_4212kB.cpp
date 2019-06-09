#include <iostream>
#include <string>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define mabs(x) ((x)>0?(x):(0-(x)))
int flr[100005],elv[100005];
int n,m,cl,ce,v;
void bins(int a[],int n,int x,int *_l,int *_r)
{
	int l=-1,r=n,m;
	while(l+1<r)
	{
		m=(l+r)/2;
		if(a[m]<=x)
			l=m;
		else
			r=m;
	}
	if(l==-1)
		l=0;
	if(a[l]==x)
		r=l;
	else r=(l+1)>=n?n-1:l+1;
	*_l=l;*_r=r;
}

int solve(int x1,int y1,int x2,int y2)
{
	int l,r;
	int costf,coste;
	int cost1,cost2,cost3;
	if(x1==x2)
		return mabs(y1-y2);

	bins(flr,cl,y1,&l,&r);
	costf=min(mabs(y1-flr[l])+mabs(x2-x1)+mabs(y2-flr[l]),
			  mabs(y1-flr[r])+mabs(x2-x1)+mabs(y2-flr[r]));

	bins(elv,ce,y1,&l,&r);
	coste=min(mabs(y1-elv[l])+mabs(x2-x1)/v+(mabs(x2-x1)%v!=0)+mabs(y2-elv[l]),
			  mabs(y1-elv[r])+mabs(x2-x1)/v+(mabs(x2-x1)%v!=0)+mabs(y2-elv[r]));

	if(cl==0)
		return coste;
	else if(ce==0)
		return costf;
	return min(costf,coste);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int x1,x2,y1,y2,i,q;
	while(cin>>n>>m>>cl>>ce>>v)
	{
		for( i = 0 ; i < cl ; i++)
		{
			cin>>flr[i];
		}
		for( i = 0 ; i < ce ; i++)
		{
			cin>>elv[i];
		}
		cin>>q;
		int ans;
		while(q--)
		{
			cin>>x1>>y1>>x2>>y2;
			ans=solve(x1,y1,x2,y2);
			cout<<ans<<endl;
		}
	}
	return 0;
}


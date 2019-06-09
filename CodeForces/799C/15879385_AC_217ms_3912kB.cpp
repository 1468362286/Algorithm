#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 100010;
pair<int,int> pii;
vector<pair<int,int> >c,d;
int max(int a,int b){return a>b?a:b;}
int SegTree[maxn<<2];

void BuildTree(int l,int r,int rt)
{
	if(l==r)
	{
		SegTree[rt]=0;
		return;
	}
	int m = (l+r)>>1;
	BuildTree(l,m,rt<<1);
	BuildTree(m+1,r,rt<<1|1);
	SegTree[rt]=SegTree[rt<<1]+SegTree[rt<<1|1];
}

int Query(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R)
		return SegTree[rt];
	int m = (l+r)>>1;
	int ans1=0,ans2=0;
	if(L<=m)
		ans1=Query(L,R,l,m,rt<<1);
	if(R>m)
		ans2=Query(L,R,m+1,r,rt<<1|1);
	return max(ans1,ans2);
}

void Update(int point,int value,int l,int r,int rt)
{
	if(l==r)
	{
		SegTree[rt]=max(value,SegTree[rt]);
		return;
	}
	int m = (l+r)>>1;
	if(point<=m)
		Update(point,value,l,m,rt<<1);
	else
		Update(point,value,m+1,r,rt<<1|1);
	SegTree[rt]=max(SegTree[rt<<1],SegTree[rt<<1|1]);
}

int main()
{
	char ch;
	int n,C,D,t1,t2,i,max_cost=0,ans=0;
	cin>>n>>C>>D;
	for( i = 0 ; i < n ; i++)
	{
		cin>>t1>>t2>>ch;
		pii=make_pair(t1,t2);
		ch=='C'?c.push_back(pii):d.push_back(pii);
		max_cost=max(t2,max_cost);
	}
	max_cost = max(max_cost,max(C,D));
	t1=t2=0;
	for( i = 0 ; i < c.size() ; i++)
		if(C>=c[i].second)
			t1=max(t1,c[i].first);
	for( i = 0 ; i < d.size() ; i++)
		if(D>=d[i].second)
			t2=max(t2,d[i].first);
		if((t1&t2)!=0)
			ans=t1+t2;
	BuildTree(0,max_cost,1);
	for( i = 0 ; i < c.size() ; i++)
	{
		t1=0;
		if(C>c[i].second)
			t1 = Query(1,C-c[i].second,0,max_cost,1);
		Update(c[i].second,c[i].first,0,max_cost,1);
		if(t1!=0)
			ans=max(ans,c[i].first+t1);
	}
	BuildTree(0,max_cost,1);
	for( i = 0 ; i < d.size() ; i++)
	{
		t1=0;
		if(D>d[i].second)
			t1 = Query(1,D-d[i].second,0,max_cost,1);
		Update(d[i].second,d[i].first,0,max_cost,1);
		if(t1!=0)
			ans=max(ans,d[i].first+t1);
	}
	cout<<ans<<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef _int64 ll;
const int maxn=100010;
int a[maxn];
int b[maxn];
int vist[maxn];
vector<int> vec[maxn];
int n,k;
int solve_tle()
{
	int i,j,z;
	for( i = 1 ; i <= n ; i++)
	{
		if(i==n)
			vec[i].push_back(1),vec[1].push_back(i);
		else
			vec[i].push_back(i+1),vec[i+1].push_back(i);
	}
	for( i = 1 ; i <= k ; i++)
	{
		if(i==k)
			int gg=1;
		for( j = 1 ; j <= n ; j++)
		{
			if(b[i]!=j)
			{
				int flag=0;
				for( z = 0 ; z < vec[b[i]].size(); z++)
				{
					if(vec[b[i]][z]==j)
					{
						flag=1;
						break;
					}
				}
				if(!flag)
					vec[b[i]].push_back(j),vec[j].push_back(b[i]);
			}
		}
	}
	int ans=0;
	for( i = 1 ; i <= n ; i++)
	{
		for( j = 0 ; j < vec[i].size() ; j++)
		{
			int to = vec[i][j];
		//	cout<<i<<" "<<to<<endl;
			ans+=a[i]*a[to];
		}
	}
	ans/=2;
	return ans;
}

ll solve()
{
	int i;
	ll sum=0;
	/*
	for( i = 1 ; i <= k ; i++)
	{
		for( j = 1 ; j <= n ; j++)
		{
			if(b[i]!=j)
				sum+=a[b[i]]*a[j];
		}
	}*/
	memset(vist,0,sizeof(vist));
	for( i = 1 ; i <= k ; i++)
		sum+=ll(a[b[i]]),vist[b[i]]=1;
	ll Sum=0;
	for( i = 1 ; i <= n ; i++)
		if(!vist[i])
			Sum+=ll(a[i])*sum;
	for( i = 1 ; i <= k ; i++)
	{
		Sum+=(sum-a[b[i]])*a[b[i]];
		sum-=a[b[i]];
	}
	int l,r;
	for( i = 1 ; i <= n ; i++)
	{
		if(i==n)
			r=1;
		else
			r=i+1;
		if(!vist[r]&&!vist[i])
			Sum+=ll(a[i])*a[r];
	}
	return Sum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(cin>>n>>k)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= k ; i++)
			cin>>b[i];
	//	cout<<solve()<<endl;
		printf("%I64d\n",solve());
	}
	return 0;
}
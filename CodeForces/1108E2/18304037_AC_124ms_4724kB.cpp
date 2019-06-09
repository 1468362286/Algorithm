#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
//mt19937 rnd(time(NULL));
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,i,j;
	cin>>n>>m;
	vector<int>a(n);
	for( i = 0 ; i < n ; i++)
		cin>>a[i];
	vector<pair<int,int> >b(m);
	vector<vector<int> > lf(n),rg(n);
	for( i = 0 ; i < m ; i++)
	{
		cin>>b[i].first>>b[i].second;
		--b[i].first;
		--b[i].second;
		lf[b[i].second].push_back(b[i].first);
		rg[b[i].first].push_back(b[i].second);
	}
	vector<int>ansv(n,-inf);
	vector<int>add(n+1,0);
	int mn = a[0];
	for( i = 0 ; i < n ; i++)
	{
		ansv[i]=max(ansv[i],a[i]-mn);
		vector<int>::iterator it;
		for( it = lf[i].begin() ; it!=lf[i].end() ; ++it)
		{
			for( j = (*it) ; j <= i ; ++j)
			{
				--add[j];
				mn=min(mn,a[j]+add[j]);
			}
		}
		mn=min(mn,a[i]+add[i]);
	}
	add=vector<int>(n+1,0);
	mn=a[n-1];
	for( i = n-1 ; i >= 0 ; --i)
	{
		ansv[i]=max(ansv[i],a[i]-mn);
		vector<int>::iterator it;
		for( it = rg[i].begin() ; it!=rg[i].end() ; ++it)
		{
			for( j = i ; j <= (*it) ; ++j)
			{
				--add[j];
				mn=min(mn,a[j]+add[j]);
			}
		}
		mn=min(mn,a[i]+add[i]);
	}
	int ans=*max_element(ansv.begin(),ansv.end());
	vector<int>res;
	for( i = 0 ; i < n ; ++i)
	{
		if(ansv[i]==ans)
		{
			for( j = 0 ; j < m ; ++j)
			{
				if(!(b[j].first<=i&&i<=b[j].second))
				{
					res.push_back(j);
				}
			}
			break;
		}
	}
	cout<<ans<<endl<<res.size()<<endl;
//	shuffle(res.begin(),res.end(),rnd);
	for(vector<int>::iterator it=res.begin();it!=res.end();++it)
		cout<<(*it)+1<<" ";
	cout<<endl;
	return 0;
}
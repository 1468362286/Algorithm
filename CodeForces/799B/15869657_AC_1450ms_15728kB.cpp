#include <iostream>
#include <string>
#include <set>
using namespace std;
const int maxn = 200010;
int a[maxn],b[maxn],c[maxn],p[maxn];
set<int> myset[4];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,x;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>p[i];
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			myset[a[i]].insert(p[i]);
		}
		for( i = 1 ; i <= n ; i++)
		{
			cin>>b[i];
			myset[b[i]].insert(p[i]);
		}
		cin>>m;
		for( i = 1 ; i <= m ; i++)
		{
			cin>>x;
			if(myset[x].size()==0)
			{
				cout<<"-1"<<endl;
			}
			else
			{
				set<int>::iterator it;
				int tmp = *myset[x].begin();
				cout<<tmp<<endl;
				for( j = 1 ; j <= 3 ; j++)
					myset[j].erase(tmp);
			}
		}
	}
	return 0;
}
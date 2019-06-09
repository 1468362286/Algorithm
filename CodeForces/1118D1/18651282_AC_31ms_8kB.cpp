#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;
const int maxn=110;
int max(int a,int b){return a>b?a:b;}
int a[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,i,j;
	while(cin>>n>>m)
	{
		int sum=0;
		for( i = 0 ; i < n ; i++)
			cin>>a[i],sum+=a[i];
		if(sum<m)
		{
			cout<<"-1"<<endl;
			continue;
		}
		sort(a,a+n,greater<int>());
		for( i = 1 ; i <= n ; i++)
		{
			int sum=0;
			for( j = 0 ; j < n ; j++)
			{
				sum+=max(a[j]-j/i,0);
			}
			if(sum>=m)
			{
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
	}
	return 0;
}
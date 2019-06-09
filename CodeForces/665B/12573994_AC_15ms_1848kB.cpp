#include <iostream>
#include <deque>
using namespace std;
deque<int> p;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,x,i,j;
	while(cin>>n>>m>>k)
	{
		for( i = 0 ; i < k ; i++)
		{
			cin>>x;
			p.push_back(x);
		}
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			for( j = 0 ; j < m ; j++)
			{
				cin>>x;
				deque<int>::iterator it;
				int cnt=0;
				for(it=p.begin();it!=p.end();it++)
				{
					cnt++;
					if(*it==x)
					{
						p.erase(it);
						ans+=cnt;
						break;
					}
				}
				p.push_front(x);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
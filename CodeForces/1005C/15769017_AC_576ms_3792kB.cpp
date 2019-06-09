#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,int>mymap;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x,cnt;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			mymap[x]++;
		}
		map<int,int>::iterator it;
		int ans=0;
		for( it= mymap.begin() ; it!=mymap.end(); it++)
		{
			x = (*it).first;
			cnt = (*it).second;
			int flag=0;
			for( i = 0 ; i < 31 ; i++)
			{
				int tmp = 1<<i;
				if(mymap.find(tmp-x)!=mymap.end())
				{
					if(mymap[tmp-x]>=2||(mymap[tmp-x]==1&&tmp-x!=x))
					{
						flag=1;
						break;
					}
				}
			}
			if(!flag)
			{
				ans+=cnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


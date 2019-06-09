#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int,bool> okl,okr;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,t,v;
	set<int> S;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n; i++)
		{
			scanf("%d",&t);
			if(i>=2)
			{
				set<int>::iterator it;
				it = S.lower_bound(t);
				if(it!=S.end()&&!okl[*it])
				{
					okl[*it]=1;v=*it;
				}
				else
				{
					it=S.upper_bound(t);
					it--;
					okr[*it]=1;
					v=*it;
				}
				printf("%d%c",v,i==n?'\n':' ');
			}
			S.insert(t);
			okl[t]=okr[t]=0;
		}
	}
	return 0;
}
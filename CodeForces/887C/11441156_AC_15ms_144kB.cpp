#include <stdio.h>
#include <set>
using namespace std;
int mp[15][15];
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,x;
	int ans = 0;
	for( i = 0 ; i < 6 ; i++)
	{
		set<int> s;
		for( j = 0 ; j < 4 ; j++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		if(s.size()==1)
			ans++;
		else if(s.size()==2)
		{
			int pre=-1,pre1=-1;
			set<int>::iterator it;
			for( it = s.begin();it!=s.end() ; it++)
			{
				if(pre==-1)
					pre=*it;
				else
					pre1=*it;
			}
			if(pre>pre1)
				swap(pre,pre1);
			mp[pre][pre1]++;
		}
		else
		{
			puts("NO");
			return 0;
		}
	}
	if(ans==2)
	{
		for( i = 1 ; i <=6 ; i++)
			for( j = 1 ; j <=  6 ; j++)
			{
				if(mp[i][j]>=2)
				{
					puts("NO");
					return 0;
				}
			}
		puts("YES");
	}
	else
		puts("NO");
	return 0;
}
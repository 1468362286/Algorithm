#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	int x,d,i,j;
	while(~scanf("%d%d",&x,&d))
	{
		ll now=1;
		vector<ll> vec;
		for( i = 30 ; i >=0 ; i--)
		{
			while(x>=(1<<i)-1)
			{
				for( j = 0 ; j < i ; j++)
				{
					vec.push_back(now);
				}
				x-=(1<<i)-1;
				now+=d+1;
				if(x==0)
					break;
			}
			if(x==0)
				break;
		}
		printf("%d\n",vec.size());
		for( i = 0 ; i < vec.size() ; i++)
			printf("%I64d ",vec[i]);
	}
	return 0;
}
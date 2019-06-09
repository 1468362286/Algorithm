#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct Node
{
	int id;
	int x;
}node[maxn];

bool cmp(Node A,Node B)
{
	if(A.x==B.x)
		return A.id<B.id;
	return A.x>B.x;
}
int main()
{
	int n,i,j,sum,x;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			sum=0;
			for( j = 0 ; j < 4 ; j++)
			{
				cin>>x;
				sum+=x;
			}
			node[i].x=sum;
			node[i].id=i+1;
		}
		sort(node,node+n,cmp);
		int ans=0;
		for( i = 0 ; i < n ; i++)
		{
			if(node[i].id==1)
			{
				ans=i+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
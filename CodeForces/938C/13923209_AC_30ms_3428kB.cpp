#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int T,i,x;
	cin>>T;
	while(T--)
	{
		cin>>x;
		if(x==0)
		{
			cout<<1<<" "<<1<<endl;
			continue;
		}
		int n=-1,m=-1;
		for( i = 1 ; i*i < x ; i++)
		{
			int j = x/i;
			if(x==i*j&&!((i^j)&1))
			{
				int u = (i+j)/2;
				int v = (j-i)/2;
				if(u/v-u/(v+1)>0)
				{
					n = u;
					m = u/v;
					break;
				}
			}
		}
		if(n!=-1)
			cout<<n<<" "<<m<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}

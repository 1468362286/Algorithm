#include <iostream>
using namespace std;

int a[1001];

int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		int cnt5=0,cnt0=0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==5)
				cnt5++;
			else if(a[i]==0)
				cnt0++;
		}
		if(cnt0>0)
		{
			cnt5=cnt5/9;
			for( i = 1 ; i <=cnt5 ; i++)
			{
				cout<<555555555;
			}
			if(cnt5==0)
			{
				cout<<0<<endl;
				return 0;
			}
			for(i=1;i<=cnt0;i++)
			{
				cout<<0;
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
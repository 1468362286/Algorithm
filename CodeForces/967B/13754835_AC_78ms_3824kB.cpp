#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int C[100010];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,b,i;
	while(cin>>n>>a>>b)
	{
		int sum=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>C[i];
			sum+=C[i];
		}
		int tmp = C[0]*a/b;
		int ans = 0;
		if(sum<=tmp)
		{
			printf("0\n");
			continue;
		}
		sort(C+1,C+n);
		int cnt=0;
		for( i = n-1 ; i >= 1 ; i--)
		{
			sum-=C[i];
			cnt++;
			if(sum<=tmp)
			{
				ans = cnt;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
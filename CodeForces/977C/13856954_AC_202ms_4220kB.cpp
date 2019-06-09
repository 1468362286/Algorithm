#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[200010];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		if(k==0&&(a[0]-1)>=1&&(a[0]-1)<=1000000000)
		{
			cout<<a[0]-1;
		}
		else if(k>=1&&a[k-1]!=a[k])
			cout<<a[k-1]<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
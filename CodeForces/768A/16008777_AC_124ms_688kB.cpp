#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int a[100010];
int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		if(n<=2)
			cout<<"0"<<endl;
		else
		{
			int l=0,r=n-1;
			while(l<n-1)
			{
				if(a[l]!=a[l+1])
					break;
				l++;
			}
			while(r>=1)
			{
				if(a[r]!=a[r-1])
					break;
				r--;
			}
			if(l<r)
			{
				cout<<r-l-1<<endl;
			}
			else
				cout<<"0"<<endl;
		}
	}
	return 0;
}
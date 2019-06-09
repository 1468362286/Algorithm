#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[1010];

int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		cout<<a[n-1]-a[0]+1-n<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,t,k,d;
	while(cin>>n>>t>>k>>d)
	{
		if(k>=n)
		{
			puts("NO");
			continue;
		}
		int guo = (n%k==0)?n/k:n/k+1;
		if((guo-1)*t>d)
		{
			puts("YES");
		}
		else
			puts("NO");
	}
	return 0;
}
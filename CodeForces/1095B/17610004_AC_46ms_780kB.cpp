#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int min(int a,int b){return a>b?b:a;}
int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<min(a[n-1]-a[1],a[n-2]-a[0])<<endl;
	}
	return 0;
}
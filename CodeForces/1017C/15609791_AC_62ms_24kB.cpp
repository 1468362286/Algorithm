#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	int n,i,j;
	while(cin>>n)
	{
		int m = sqrt(n);
		int len = n/m;
		for( i = n ; i > 0 ; i-=m)
			for( j = m ; j > 0 ; j--)
			{
				if(i-j+1<=0)
					continue;
				cout<<i-j+1<<" ";
			}
		cout<<endl;
	}
	return 0;
}

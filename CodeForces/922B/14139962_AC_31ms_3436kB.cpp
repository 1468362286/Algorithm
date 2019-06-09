#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		int c;
		int cnt=0;
		for( i = 1 ; i <= n ; i++)
			for( j = i ; j <= n ; j++)
			{
				c =i^j;
				if(((i+j)>c&&(i+c)>j&&(j+c)>i)&&c<=n)
				{
					if(abs(i-j)<c&&abs(i-c)<j&&abs(j-c)<i)
					{
					//	printf("%d %d %d\n",i,j,c);
						cnt++;
					}
				}
			}
		cout<<cnt/3<<endl;
	}
	return 0;
}
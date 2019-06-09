#include <iostream>
using namespace std;

int main()
{
	int A,B,c[100],b[100],i,sum,num;
	while(cin>>A>>B)
	{
		i = 0;
		sum=0;
		while(A)
		{
			c[i] = A%10;
			A/=10;		
			sum+=c[i];
			i++;
		}
		i = 0;
		num=0;
		while(B)
		{
			b[i] = B%10;
			B/=10;
			num+=b[i];
			i++;
		}
		cout<<sum*num<<endl;
	}
	return 0;
}
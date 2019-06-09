#include <iostream>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x%2!=1)
			cout<<x/2+(x%2==0?0:1)<<endl;
		else if(x%3!=1)
			cout<<x/3+(x%3==0?0:1)<<endl;
		else if(x%4!=1)
			cout<<x/4+(x%4==0?0:1)<<endl;
		else if(x%5!=1)
			cout<<x/5+(5%3==0?0:1)<<endl;
		else if(x%6!=1)
			cout<<x/6+(x%6==0?0:1)<<endl;
		else if(x%7!=1)
			cout<<x/7+(x%7==0?0:1)<<endl;
	}
	return 0;
}
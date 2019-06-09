#include <iostream>
#include <string>
using namespace std;
const int maxn = 55;


int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,x,i;
	while(cin>>n)
	{
		int one=0,two=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x==1)one++;
			else two++;
		}
		if(two){cout<<2<<" ";two--;}
		if(one){cout<<1<<" ",one--;}
		for( i = 0 ; i < two ; i++)
			cout<<2<<" ";
		for( i = 0 ; i < one ; i++)
			cout<<1<<" ";
		cout<<endl;
	}
	return 0;
}
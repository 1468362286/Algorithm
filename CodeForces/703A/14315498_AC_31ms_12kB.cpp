#include <iostream>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,x,y;
	while(cin>>n)
	{
		int cnt=0;
		int cn=0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>x>>y;
			if(x>y)cnt++;
			else if(x<y)cn++;
		}
		if(cnt>cn)
		{
			cout<<"Mishka"<<endl;
		}
		else if(cnt<cn)
		{
			cout<<"Chris"<<endl;
		}
		else
			cout<<"Friendship is magic!^^"<<endl;
	}
	return 0;
}
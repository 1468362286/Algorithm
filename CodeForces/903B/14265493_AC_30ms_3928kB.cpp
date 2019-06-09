#include <iostream>
#include <string>
using namespace std;
int a[1000010];
int main()
{
	//freopen("in.txt","r",stdin);
	int a1,a2,h1,h2,c1;
	while(cin>>h1>>a1>>c1)
	{
		cin>>h2>>a2;
		int cnt=0;
		while(h2>0)
		{
			cnt++;
			if(h1>a2||h2<=a1)
			{
				a[cnt]=1;
				h1-=a2;
				h2-=a1;
			}
			else
			{
				a[cnt]=2;
				h1=h1+c1-a2;
			}
		}
		cout<<cnt<<endl;
		for(int i = 1 ; i <= cnt ; i++)
			if(a[i]==1)
				cout<<"STRIKE"<<endl;
			else
				cout<<"HEAL"<<endl;
	}
	return 0;
}
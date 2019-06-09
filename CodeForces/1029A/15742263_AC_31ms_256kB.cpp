#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	string s;
	while(cin>>n>>k)
	{
		cin>>s;
		int tmp=0;
		int flag=0;
		for( i = n-1 ; i >= 1 ; i--)
		{
			string s1=s.substr(0,i);
			string s2=s.substr(n-i);
			if(s.substr(0,i)==s.substr(n-i))
			{
				flag=0;
				tmp=i;
				break;
			}
			else
				flag=1;
		}
		if(flag)
		{
			while(k--)
				cout<<s;
			cout<<endl;
		}
		else
		{
			cout<<s;
			k--;
			while(k--)
			{
				cout<<s.substr(tmp);
			}
		}
		cout<<endl;
	}
	return 0;
}
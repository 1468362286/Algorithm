#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	string s1,s2,s,p;
	while(cin>>s1>>s2)
	{
		cin>>n;
		cout<<s1<<" "<<s2<<endl;
		while(n--)
		{
			cin>>s>>p;
			if(s1==s)
				s1=p;
			else
				s2=p;
			cout<<s1<<" "<<s2<<endl;
		}
	}
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[200];
int main()
{
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		if(n==1)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		int flag=0;
		memset(a,0,sizeof(a));
		for(int i = 0 ; i < n ; i++)
		{
			if(a[s[i]]==1)
			{
				flag=1;
				break;
			}
			a[s[i]]++;
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
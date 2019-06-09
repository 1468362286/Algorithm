#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int cnt=0;
		for( i = 0 ; i < s.size()-1 ; i++)
		{
			if(s[i]!=s[i+1])
			{
				cnt++;
				i++;
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}
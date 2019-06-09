#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	cin>>s;
	int x=0,y=0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i]=='0')
		{
			cout<<1<<" "<<x+1<<endl;
			x=++x%4;
		}
		else
		{
			cout<<3<<" "<<y+1<<endl;
			y=(y+2)%4;
		}
	}
	return 0;
}
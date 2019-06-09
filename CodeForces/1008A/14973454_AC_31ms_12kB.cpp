#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool judge(char c)
{
	if(c=='a'||c=='o'||c=='u'||c=='i'||c=='e')
		return true;
	else
		return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		int flag=0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			if(!judge(s[i]))
			{
				if(s[i]=='n')
					continue;
				if(i!=s.size()-1)
				{
					if(!judge(s[i+1]))
					{
						flag=1;
						break;
					}
				}
				else
				{
					if(s[i]!='n')
					{
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
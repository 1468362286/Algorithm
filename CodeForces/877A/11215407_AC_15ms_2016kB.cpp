#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
const int maxn = 110;
string ch;
string s[5]={"Danil", "Olya", "Slava", "Ann" ,"Nikita"};

int main()
{
	int i,j;
	//freopen("in.txt","r",stdin);
	while(cin>>ch)
	{
		string tmp,ss;
		int count = 0;
		for( i = 0 ; i < 5 ; i++)
		{
			tmp = ch;
			while(tmp.find(s[i])!=-1)
			{
				count++;
				int pos = tmp.find(s[i]);
				ss = tmp.substr(pos+s[i].size(),tmp.size());
				tmp = ss;
			}
		}
		if(count==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


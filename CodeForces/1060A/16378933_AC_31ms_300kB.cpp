
 #include <iostream>
#include <string>
using namespace std;
int min(int a,int b){return a>b?b:a;}
int main()
{
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int cnt=0;
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i]=='8')
				cnt++;
		cout<<min(n/11,cnt)<<endl;
	}
	return 0;
}
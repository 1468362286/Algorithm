#include <iostream>
#include <string>
#include <set>
using namespace std;
set<char> myset;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	string s;
	while(cin>>n>>k)
	{
		myset.clear();
		cin>>s;
		for( i = 0 ; i < s.size() ; i++)
		{
			myset.insert(s[i]);
		}
		if(s.size()<k)
		{
			cout<<s;
			for( i = 0 ; i < k-n ; i++)cout<<(*myset.begin());
			cout<<endl;
			continue;
		}
		int flag=0;
		for( i = s.size()-1-(n-k) ; i >= 0 ; i--)
		{
			set<char>::iterator it;
			for( it = myset.begin() ; it!=myset.end(); it++)
			{
				if((*it)>s[i])
				{
					flag=1;
					s[i]=(*it);
					break;
				}
			}
			if(flag)break;
			else {
				s[i]=(*myset.begin());			
			} 
		}
		cout<<s.substr(0,k)<<endl;
	}
	return 0;
}

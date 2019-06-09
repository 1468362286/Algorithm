#include <iostream>
#include <string>
#include <algorithm>
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
		cin>>s;
		myset.clear();
		for( i = 0 ; i < s.size() ; i++)
		{
			myset.insert(s[i]);
		}
		int sum=0;
		int cnt=0;
		set<char>::iterator it;
		char pre;
		for( it = myset.begin() ; it!=myset.end() ; it++)
		{
			if(it==myset.begin())
			{
				pre=(*it);
				sum+=(*it)-'a'+1;
				cnt++;
			}
			else if((*it)-pre>1)
			{
				sum+=(*it)-'a'+1;
				cnt++;
				pre=(*it);
			}
			if(cnt==k)
				break;
		}
		if(cnt<k)
			cout<<"-1"<<endl;
		else
			cout<<sum<<endl;
	}
	return 0;
}
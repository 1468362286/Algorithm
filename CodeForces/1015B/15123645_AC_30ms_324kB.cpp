#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,tmp;
	string s,t;
	vector<int> ans;
	while(cin>>n)
	{
		cin>>s>>t;
		ans.clear();
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]!=t[i])
			{
				int flag=0;
				for( j = i+1 ; j < n ; j++)
				{
					if(t[i]==s[j])
					{
						flag=1;
						tmp = j;
						break;
					}	
				}
				if(flag)
				{
					for( j = tmp-1 ; j >= i; j--)
					{
						swap(s[j],s[j+1]);
						ans.push_back(j+1);
					}
				}
				else
				{
					cout<<"-1"<<endl;
					return 0;
				}
			}
		}
		cout<<ans.size()<<endl;
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
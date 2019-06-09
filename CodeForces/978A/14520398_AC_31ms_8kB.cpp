#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int a[100];
map<int,bool> mymap;

int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		mymap.clear();
		vector<int>ans;
		ans.clear();
		for( i = n-1 ; i>=0 ; i--)
		{
			if(mymap[a[i]]==false)
			{
				ans.push_back(a[i]);
				mymap[a[i]]=true;
			}
		}
		cout<<ans.size()<<endl;
		for( i = ans.size()-1 ; i>=0 ; i--)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int,int>mymap;
int main()
{
	int n,x;
	while(cin>>n)
	{
		mymap.clear();
		int ans=0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>x;
			mymap[x]++;
			if(mymap[x]>ans)
				ans=mymap[x];
		}
		cout<<n-ans<<endl;
	}	
	return 0;
}	

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	vector<int>vec;
	while(cin>>n)
	{
		vec.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x%2==0)
				vec.push_back(x-1);
			else
				vec.push_back(x);
		}
		for( i = 0 ; i < n ; i++)
		{
			cout<<vec[i]<<" "; 
		}
		cout<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2010;
struct Node
{
	int x,id;
}node[maxn];

bool cmp(Node A,Node B)
{
	return A.x<B.x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,k;
	vector<int> vec;
	while(cin>>n>>k)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>node[i].x;
			node[i].id = i;
		}
		sort(node,node+n,cmp);
		int sum = 0;
		vec.clear();
		for( i = n-1 ; i >n-1-k ; i--)
		{
			sum+=node[i].x;
			vec.push_back(node[i].id);
		}
		cout<<sum<<endl;
		sort(vec.begin(),vec.end());
		/*
		for( i = 0 ; i < vec.size() ; i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<endl;*/
		if(k==1)
		{
			cout<<n<<endl;
			continue;
		}
		for( i = 1 ; i < vec.size() ; i++)
		{
			if(i==1)
				cout<<vec[i]<<" ";
			else
				cout<<vec[i]-vec[i-1]<<" ";
		}
		cout<<n-vec[k-1]<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef _int64 ll;
const int maxn = 510;
const int inf = 0x3f3f3f3f;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= n ;j++)
			{
				if(i%j==0&&i*j>n&&i/j<n)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		cout<<"-1"<<endl;
	}
	return 0;
}
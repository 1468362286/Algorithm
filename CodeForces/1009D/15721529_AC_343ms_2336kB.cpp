#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int> >vec;
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		if(m<n-1)
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		vec.clear();
		int flag=0;
		int cnt=0;
		for( i = 1 ; i <= n ; i++)
			for( j = i+1 ; j <= n ; j++)
			{
				if(gcd(i,j)==1)
				{
					cnt++;
					vec.push_back(make_pair(i,j));
					if(cnt==m)
					{
						flag=1;
						goto loop;
					}
				}
			}
loop:	if(!flag)cout<<"Impossible"<<endl;
		else
		{
			cout<<"Possible"<<endl;
			for( i = 0 ; i < vec.size() ; i++)
			{
				cout<<vec[i].first<<" "<<vec[i].second<<endl; 
			}
		}
	}
	return 0;
}
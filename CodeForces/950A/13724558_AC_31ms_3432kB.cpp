#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline int min(int a,int b){return a>b?b:a;}
int main()
{
	int l,r,a;
	while(cin>>l>>r>>a)
	{
		if(l>r)swap(l,r);
		while(a)
		{
			if(l<r)
			{
				l++;
				a--;
			}
			else
			{
				r++;
				a--;
			}
		}
		cout<<min(l,r)*2<<endl;
	}
	return 0;
}
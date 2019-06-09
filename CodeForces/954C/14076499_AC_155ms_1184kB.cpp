#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int a[300010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,y,i;
	while(cin>>n)
	{
		y=1;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			if(i==0)
				continue;
			if(a[i]==a[i-1])
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(abs(a[i]-a[i-1])!=1)
			{
				y=abs(a[i]-a[i-1]);
			}
		}
		/*
		for( i = 1 ; i < n ; i++)
		{
			if(abs(a[i]-a[i-1])!=1&&abs(a[i]-a[i-1])!=y)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			if(a[i]%y==0&&a[i]-a[i]==1&&y!=1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else if(a[i]%y==1&&a[i]-a[i-1]==1&&y!=1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		*/
		for (int i = 1; i < n; i++) {
        if((abs(a[i] - a[i - 1]) != 1 && abs(a[i] - a[i - 1]) != y)){
           // cout<<"++"<<endl;
            cout<<"NO"<<endl;return 0;
        }
        if(a[i] % y == 0 && a[i - 1] - a[i] == 1 && y != 1) {
            //cout<<"--"<<endl;
            cout<<"NO"<<endl;return 0;
        } else if(a[i] % y == 1 && a[i] - a[i - 1] == 1 && y != 1) {
           // cout<<"**"<<endl;
            cout<<"NO"<<endl;return 0;
        }
		}
		cout<<"YES"<<endl<<1000000000<<' '<<y<<endl;
	}
	return 0;
}
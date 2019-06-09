#include <iostream>
#include <string>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int v1,v2,v3,vm,i,j,k,V1,V2,V3;
	while(cin>>v1>>v2>>v3>>vm)
	{
		int flag=0;
		for( i = v1 ;  2*v1 >= i; i++)
			for( j = v2 ; 2*v2 >= j; j++)
				for( k = v3 ; 2*v3 >= k; k++)
				{
					if(vm<=k&&2*vm>=k)
					{
						if(2*vm<i&&2*vm<j&&i>j&&j>k)
						//if(i>j&&j>k)
						{
							V1=i;
							V2=j;
							V3=k;
							flag=1;
							goto loop;
						}
					}
				}
loop: if(flag)cout<<V1<<endl<<V2<<endl<<V3<<endl;
	  else cout<<-1<<endl;
	}
	return 0;
}
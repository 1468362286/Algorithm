#include <iostream>
#include <string>
using namespace std;
char a[110][110];
int cnt[110][110];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j,t,c1,c2,c3,c4;
	while(cin>>n>>k)
	{
		int maxi = -1;
		for( i = 0 ; i < n ; i++)
			scanf("%s",&a[i]);
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < n ; j++)
			{	
				
				if( a[i][j]=='.')
				{
					c1=c2=c3=c4=0;	
					for( t = 1 ; t < k && i+t<n ; t++)
					{
						if(a[i+t][j]=='.')
							c1++;
						else
							break;
					}
					for( t = 1 ; t < k && i-t>=0 ; t++)
					{
						if(a[i-t][j]=='.')
							c2++;
						else
							break;
					}
					for( t = 1 ; t < k && j+t<n; t++)
					{
						if(a[i][j+t]=='.')
							c3++;
						else
							break;
					}
					for( t = 1 ; t < k && j-t >=0 ; t++)
					{
						if(a[i][j-t]=='.')
							c4++;
						else
							break;
					}
					cnt[i][j]=(c1+c2+1>=k?c1+c2+2-k:0)+(c3+c4+1>=k?c3+c4+2-k:0);
				}
				
			}
		int ansi,ansj;
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < n ; j++)
			{
				if(maxi<cnt[i][j])
				{
					ansi=i+1;
					ansj=j+1;
					maxi=cnt[i][j];
				}
			}
		printf("%d %d\n",ansi,ansj);
	}
	return 0;
}
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[4][110][110];
int cnt1[4],cnt2[4];
inline int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	while(cin>>n)
	{
		getchar();
		for( k = 0 ; k < 4 ; k++)
		{
			for( i = 0 ; i < n ; i++)
			{
				scanf("%s",&a[k][i]);
			}
		}
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for( k = 0 ; k < 4 ; k++)
		{
			for( i = 0 ; i < n ;i++)
			{
				for( j = 0 ; j < n ;j++)
				{
					if((i+j)%2==0)
					{
						if(a[k][i][j]-'0'==0)	
						{
							cnt1[k]++;
						}
						else
						{
							cnt2[k]++;
						}
					}
					else 
					{
						if(a[k][i][j]-'0'==1)
						{
							cnt1[k]++;
						}
						else
						{
							cnt2[k]++;
						}
					}
				}
			}
		}
		int ans=n*n*4;
		for( i = 0 ; i < 3 ; i++)
		{
			for( j = i+1 ; j < 4 ; j++)
			{
				int sum=0;
				for( k = 0 ; k < 4 ; k++)
				{
					if(k!=i&&k!=j)
						sum+=cnt2[k];
				}
				sum+=(cnt1[i]+cnt1[j]);
				ans=min(ans,sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

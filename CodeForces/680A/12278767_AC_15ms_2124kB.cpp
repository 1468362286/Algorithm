#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int Hash[101];
int vist[101];
int main()
{
	//freopen("in.txt","r",stdin);
	int a[5];
	int i;
	int maxi=-1;
	int sum=0;
	for( i = 0 ; i < 5 ; i++)
		scanf("%d",&a[i]),Hash[a[i]]++,sum+=a[i];
	for( i = 0 ; i < 5 ; i++)
		if(Hash[a[i]]==2&&!vist[a[i]])
		{
			vist[a[i]]=1;
			maxi=max(maxi,2*a[i]);
		}
		else if(Hash[a[i]]>=3)
		{
			maxi=max(maxi,3*a[i]);
		}
	if(maxi==-1)
		printf("%d\n",sum);
	else
		printf("%d\n",sum-maxi);
	return 0;
}
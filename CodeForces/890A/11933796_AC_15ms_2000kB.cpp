#include <stdio.h>
int a[7];
int sum = 0;
int flag;
void dfs(int step,int pos,int num)
{
	if(step==3)
	{
		if(num*2==sum)
		{
			flag = 1;
		//	return;
		}
		return;
	}

	for(int j = pos ; j < 6 ; j++)
		dfs(step+1,j+1,num+a[j]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	sum = 0,flag=0;
	int i;
	for( i = 0 ; i < 6 ; i++)
		scanf("%d",a+i),sum+=a[i];
	for( i = 0 ; i < 3 ; i++)
		dfs(0,i,0);
	printf("%s\n",flag?"YES":"NO");
	return 0;
}
#include <stdio.h>
#include <iostream>
using namespace std;
int a[1000010];
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
int main()
{
	int n,x;
	while(~scanf("%d",&n))
	{
		int flag = 0;
		for(int i = 0 ; i < n ; i++)
		{
			x = read();
			a[i]=x;
		}
		for(int j = 0 ; j < n ; j++)
		{
			if(a[j]%2==1)
			{
				flag = 1;
				break;
			}
		}
		printf("%s\n",flag?"First":"Second");
	}
	return 0;
}
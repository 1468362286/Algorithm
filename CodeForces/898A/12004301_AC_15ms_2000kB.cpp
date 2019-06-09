#include <stdio.h>

int main(){
	int n;
	while (~scanf("%d",&n)){
		int temp=n;
		int cnt =0;
		if (n==0)cnt =1;
		while(temp){
		   temp=temp/10;
			cnt++;
			}
//			printf("%d\n",cnt);
//			printf ("%d\n",temp);
		if ((n%10)==0)
		printf ("%d\n",n);
		else {
			if((n%10)>5)
		printf ("%d\n",cnt==1?10:n-(n%10)+10);
		else printf ("%d\n",cnt==1?0:n-(n%10));
		}
		}
	return 0;
	}
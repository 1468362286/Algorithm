#include <stdio.h>
#include <string.h>
const int mod = 10000;
typedef struct Matrix
{
	int mat[2][2];
}matrix;

matrix A,B;

Matrix matrix_mul(matrix a,matrix b)
{
	matrix c;
	memset(c.mat,0,sizeof(c.mat));
	for(int i = 0 ; i < 2 ; i++)
		for(int k = 0 ; k < 2 ; k++)
			for(int j = 0 ; j < 2 ;  j++)
			{
				if(a.mat[i][k]&&b.mat[k][j])
				{
					c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
					c.mat[i][j]%=mod;
				}
			}
	return c;
}

Matrix matrix_quick_power(matrix a,int k)
{
	matrix b;
	memset(b.mat,0,sizeof(b.mat));
	for(int i = 0 ; i < 2 ; i++)
	{
		b.mat[i][i]=1;
	}
	while(k)
	{
		if(k%2==1)
		{
			b = matrix_mul(a,b);
			k-=1;
		}
		else
		{
			a = matrix_mul(a,a);
			k/=2;
		}
	}
	return b;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		if(n==-1)
			break;
		A.mat[0][1]=A.mat[0][0]=A.mat[1][0]=1;
		A.mat[1][1]=0;
		B = matrix_quick_power(A,n);
		printf("%d\n",B.mat[1][0]);
	}
	return 0;
}
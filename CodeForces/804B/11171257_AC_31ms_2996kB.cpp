#include <stdio.h>
#include <string.h>
static const int INF=0x3f3f3f3f;

template<typename T,typename U>
static void amin(T &x,U y)
{
	if(y<x)
		x=y;
}
template<typename T,typename U>
static void amax(T &x, U y)
{
	if(x<y)
		x=y;
}

template<int MOD>
struct ModInt
{
//	static const int Mod = MOD;
	enum{Mod=MOD};
	unsigned x;
	ModInt():x(0){}
	ModInt(signed sig)
	{
		int sigt = sig%MOD;
		if(sigt<0)
			sig+=MOD;
		x = sigt;
	}
	ModInt(signed _int64 sig)
	{
		int sigt = sig%MOD;
		if(sigt<0)
			sig+=MOD;
		x = sigt;
	}
	int get()const
	{
		return (int)x;
	}

	ModInt &operator+=(ModInt that)
	{
		if((x+=that.x)>=MOD)
			x-=MOD;
		return *this;
	}
	ModInt &operator-=(ModInt that)
	{
		if((x+=MOD-that.x)>=MOD)
			x-=MOD;
		return *this;
	}
	ModInt &operator*=(ModInt that)
	{
		x=(unsigned _int64)
			x*that.x%MOD;
		return *this;
	}
	ModInt operator+(ModInt that)const
	{
		return ModInt(*this)+=that;
	}
	ModInt operator-(ModInt that)const
	{
		return ModInt(*this)-=that;
	}
	ModInt operator*(ModInt that)const
	{
		return ModInt(*this)*=that;
	}
};

typedef ModInt<1000000007>mint;

int main()
{
	//freopen("in.txt","r",stdin);
	char S[1000001];
	while(~scanf("%s",S))
	{
		int n = (int)strlen(S);
		mint sum;
		mint ans;
		for(int i = n-1 ; i >=0 ; --i)
		{
			if(S[i]=='a')
			{
				ans+=sum;
				sum*=2;
			}
			else
			{
				sum+=1;
			}
		}
		printf("%d\n",ans.get());
	}
	return 0;
}





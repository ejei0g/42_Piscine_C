# include <stdio.h>

int		sum(int n)
{
	int ret =0;
	for(int i = 1; i <=n; ++i){
		ret += i;
	}
	printf("%d\n", ret);
	return ret;
}

int		reculsiveF(int n)
{
	if(n == 1) return 1; //end option
	
	return n + reculsiveF(n-1);
}

int		digitR(int n)
{
	if(n == 0) return 0;
	digitR(n/10);
	printf("%d", n%10);
}

int		main(void)
{
	digitR(143);
}


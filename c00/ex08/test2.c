#include <stdio.h>

void whilee(int n)
{
	if(n==10) return ;
	while(n<10)
	{
		printf("%d", n);
		whilee(n+1);
		printf("\n");
		n++;

	}
}

void recPractice(int n)
{
	if(n == 5) return ;
	recPractice(n+1);
	printf("%d",n);
}

int main(void)
{
	recPractice(1);
}

#include <unistd.h>

void ft_write(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

int main(void)
{
	int a = 0;
	while (a < 9)
	{
		ft_write(3 + 48, 4 + 48, 5 + 48);
		a++;
	}
	return (0);
}

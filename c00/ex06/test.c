#include <stdio.h>
#include <unistd.h>

int ft_print(int a) {
	int NN;
	int n;

	NN = a / 10 + 48;
	n = a % 10 + 48;

	write(1 , &NN, 1);
	write(1 , &n, 1);
}

int main(void)
{
	ft_print(99);
	ft_print(9);
	return (0);
}

#include <unistd.h>

void	ft_print_write(int nbr)
{
	int num;

	num = nbr + 48;
	write(1, &num, 1);
}

void	ft_reculsive(int nbr)
{
	if (nbr == 0)
		return ;
	ft_reculsive(nbr / 10);
	ft_print_write(nbr % 10);
}

void	ft_rec_com(int[] nbr)
{
	int num;

	num = 5;
	while (num > 0)
	{
		
		num--;

	}
}


void	full(int depth, int R)
{
	int i;
	if (
}


int		main(void)
{
	ft_reculsive(1032);
	return (0);
}

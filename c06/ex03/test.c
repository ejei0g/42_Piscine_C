#include <stdio.h>

void	ft_swap(char **a, char **b)
{
	char *tm;
	tm = *a;
	*a = *b;
	*b = tm;	
}

int main(void)
{
	char **arr;

	arr[0] = "abcdefg";
	arr[1] = "1233452";
	ft_swap(&arr[0], &arr[1]);

	printf("%p\n", arr);
	printf("%s\n", arr[1]);
	return (0);
}

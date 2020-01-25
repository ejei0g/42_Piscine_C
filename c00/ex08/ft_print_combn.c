/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 05:08:37 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/25 02:04:01 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#define R 5
#define N 4
void	ft_print_comb(void)
{
	int i = 0;
	int arr[6] = {0,1,2,3,4,5};
	int selected[6];

	while (i == 5)
	{
		
		selected[i] = arr[i] 
		i++;
	}	
	
	

}


void	ft_recul(int n)
{
	if (n == 0)
		return ;
	ft_recul(n / 10);

}

void	ft_print_combn(int n)
{
	int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sel[n];
	
	for(int i=0; i<10;i++){
		for(int j=i+1;j<10;j++){
			printf("%d,%d",i,j);	
		}
	}
	
	while(i<10)
	{

		i++;
	}
}
void whilewhile(int n)
{
	if(n==10) return ; 
	while(n<10)
	{
		printf(n);
		whilewhile(n+1);
		n++;
	}		
}


int selected[R];
void full(int depth)
{
	int i;
	if (R == depth)
		printf("selected");
	printf("\n");
	
	for(i=1;i<=N;i++) {
	selected[depth]=i;
		full(depth+1);
	}
}
void onepick(void)
{
	int n = 10;
	while (n > 0)
	{
		printf("%d",n);
	n--;
	}
}

void pick(int n, int[] picked, int toPick) {
	if(toPick ==0) {printf("selected num");}

	int smallest;

	for (int next = smallist; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}	

int		main(void)
{
	ft_print_digit(1);
	return (0);
}

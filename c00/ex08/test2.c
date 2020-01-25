/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:07:44 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/25 23:11:25 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putint(int nbr)
{
	int num;

	num = nbr + 48;
	write(1, &num, 1);
}

void recPractice(int n, int numlist, int* arr, int digit)
{
	if(n == digit) return ;

	/*작게 실행시킬 명령.
	 *선택을 한다. 0~10
	 * 조건을 만족한다면 저장합니다.
	 *	
	 * */
	
	while(numlist < 10) // 10개 선택하는 것:
	{
		arr[n] = numlist; //선택한 값을 arr에
		if(n == digit - 1) {
			for(int i=0; i<digit;i++){
				


				printf("%d",arr[i]);
			}
			
			if(arr[0] == digit + 4)
				return ;
			else
				printf(", ");
		}

		recPractice(n+1, numlist +1, arr, digit);

		numlist++;
	}
}

int main(void)
{
	int num = 0;
	int digit = 3;
	int selected[digit];
	recPractice(num, 0, selected, digit);
}

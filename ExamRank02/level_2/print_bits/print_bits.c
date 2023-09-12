/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:14:54 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:39:06 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int			i = 7;
	unsigned char bit;

	while(i >= 0)
	{
		bit = octet >> i & 1;
		bit += 48;// 48 == '0' en ascii
		write(1, &bit, 1);
		--i;
	}
}
/*
int main(void)
{
	unsigned char num = 4;
	print_bits(num);
	return (0);
}
*/

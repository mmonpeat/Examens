/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:40:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:40:17 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char res = 0;

	while(i < 8)
	{
		res = (res << 1) | (octet >> i & 1);
		//res = (res * 2) + (octet >> i & 1);
		i++;
	}
	return(res);
}
/*
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

int main(void)
{
	unsigned char num = 2;
	print_bits(reverse_bits(num));
	return(0);
}
*/

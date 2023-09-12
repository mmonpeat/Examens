/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:19:47 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:43:17 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

/*
int main(void)
{
	unsigned char num = 4;
	swap_bits(num);
	return (0);
}
*/
/*
original = 0 1 0 0 0 0 0 1

org << 4 = 0 0 0 1 0 0 0 0
org >> 4 = 0 0 0 0 0 1 0 0

final    = 0 0 0 1 0 1 0 1
*/

/*
 MILLOR AQUESTA NO
unsigned char swap_bits(unsigned char octet)
{
	int i = 7;
	unsigned char res;
	unsigned char temp;

	while(i >= 0)
	{
		res += (octet >> i & 1) + 48;
		if (i >
		--i;
	}
	return (res);
}*/

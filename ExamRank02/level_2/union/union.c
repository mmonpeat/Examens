/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:09:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/06/03 13:11:09 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int chack(char *str, int c, int index)
{
	int i = 0;

	while(i < index)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
int main(int argc, char **argv)
{
	int	i = 0;
	int j = 0;
	int k = 0;

	if (argc == 3)
	{
		while(argv[1][i] != '\0')
			i++;
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		while(k < i)
		{
			if(chack(argv[1], argv[1][k], k) == 1)
				write(1, &argv[1][k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
}

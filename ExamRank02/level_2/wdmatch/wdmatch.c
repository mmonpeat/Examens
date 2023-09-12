/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:28:00 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/06/03 14:14:48 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return(i);
}
int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int s = 0;
	char str[10000];

	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			while(argv[2][j] != '\0')
			{
				if(argv[1][i] == argv[2][j])
				{
					str[s] = argv[1][i];
					s++;
					break;
				}
				j++;
			}
			i++;
		}
		str[s] = '\0';
		if (i == ft_strlen(str))
			write(1, str, s);
	}
	write(1, "\n", 1);
	return (0);
}

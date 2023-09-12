/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:03:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/25 12:07:10 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int ft_inter(char *str, char c, int len)
{
	int i = 0;

	while (str[i] && (i < len || len == -1))
		if (str[i++] == c)
			return (1);
	return (0);
}
int main(int argc, char **argv)
{
	int len;

	if (argc == 3)
	{
		len = 0;
		while (argv[1][len])
		{
			if (!ft_inter(argv[1], argv[1][len], len) && ft_inter(argv[2], argv[1][len], -1))
				write(1, &argv[1][len], 1);
			len++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

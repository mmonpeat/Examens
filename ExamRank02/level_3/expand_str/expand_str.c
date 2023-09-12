/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:37:20 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 16:55:42 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_wordlen(char *s);

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int len = 0;
		int spaces = 1;
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] ==  '\t')
				i++;
			len = ft_wordlen(&av[1][i]);
			if (len > 0 && spaces == 0)
				write(1, "   ", 3);
			spaces = 0;
			write(1, &av[1][i], len);
			i += len;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int ft_wordlen(char *s)
{
	int i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:50:18 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 16:14:04 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_spaces(char *s, int i);
int	ft_wordlen(char *s);

int main(int ac, char **av)
{
	int i = 0;
	int len = 0;
	int spaces = 1;

	if (ac == 2)
	{
		i = ft_is_spaces(av[1], i);
		while (av[1][i])
		{
			if (spaces == 0)
				write(1, " ", 1);
			len = ft_wordlen(&av[1][i]);
			write(1, &av[1][i], len);
			i += len;
			spaces = 0;
			i = ft_is_spaces(av[1], i);
		}
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_is_spaces(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int	ft_wordlen(char *s)
{
	int i = 0;

	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}

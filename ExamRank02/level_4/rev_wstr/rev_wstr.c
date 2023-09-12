/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:25:46 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 19:26:11 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void	ft_rev_wstr(char *s);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
static void	ft_rev_wstr(char *s)
{
	int i = 0;
	int j = 0;
	int flag = 1;

	while (s[i])
		i++;
	while (i >= 0)
	{
		while (i >= 0 && (s[i] == '\0' || s[i] == ' ' || s[i] == '\t'))
			--i;
		j = i;
		while (j >= 0 && s[j] != ' ' && s[j] != '\t')
			--j;
		if (flag == 0)
			write(1, " ", 1);
		write(1, &s[j + 1], (i - j));
		flag = 0;
		i = j;
	}
}

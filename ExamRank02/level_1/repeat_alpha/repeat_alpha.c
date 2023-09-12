/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:16:51 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/20 15:45:37 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str);
void	ft_putchar(char c, int i);

int main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);

	write (1, "\n", 1);
	return (0);
}

void repeat_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			ft_putchar(*str, *str + 1 - 'a');
		else if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str, *str + 1 - 'A' );
		else
			write(1, str, 1);
		++str;
	}
}

void ft_putchar(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		--n;
	}
}

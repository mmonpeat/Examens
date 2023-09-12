/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:01:52 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/04/20 13:09:01 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

/*int main()
{
	char str[] = "hola que tal?";
	ft_putstr(str);
	return (0);
}*/

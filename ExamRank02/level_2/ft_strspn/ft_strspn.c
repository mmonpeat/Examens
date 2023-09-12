/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:09:37 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:37:16 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strchr(const char *accept, int c)
{
	while(*accept != '\0')
	{
		if(*accept == c)
			return (1);
		accept++;
	}
	return (0);
}
size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while(s[i] != '\0')
	{
		if(ft_strchr(accept, s[i]) == 0)
			break;
		i++;
	}
	return (i);
}
/*
int main()
{
	printf("%lu\n", ft_strspn("hola", "ho"));
	printf("%lu", strspn("hola","ho"));
	return (0);
}
*/

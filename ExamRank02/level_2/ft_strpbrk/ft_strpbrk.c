/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:23:41 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:35:26 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>


char *ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	while(*s1)
	{
		i = 0;
		while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;
	}
	return (0);
}
/*
int main()
{
	char s1[13] = "Hola a todos";
   	char s2[5] = "a t";

   	printf( "s1=%s\n", s1 );
   	printf( "s2=%s\n", s2 );
   	printf( "strpbrk(s1,s2) = %s\n", ft_strpbrk( s1, s2 ) );
   	printf( "strpbrk(s1,s2) = %s\n", strpbrk( s1, s2 ) );
	return(0);
}
*/

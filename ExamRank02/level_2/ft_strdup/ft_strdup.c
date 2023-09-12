/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:06:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:34:57 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
	
char *ft_strdup(char *s1)
{
	int 	i;
	int 	len;
	char 	*s2;

	len = 0;
	while(s1[len] != '\0')
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (s2 == NULL)
		return (NULL);
	while(s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int  main()
{
	char *str = "holaaaaa";
	char *func = ft_strdup(str);
	printf("%s", func);
	return (0);
}
*/

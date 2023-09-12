/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:55:10 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/19 15:35:52 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int len  = 0;
	char temp;

	while(str[len])
		len++;
	while(i < len / 2)
	{
		temp = str[i];
		str[i] = str[len -1 -i];
		str[len -1 -i] = temp;
		i++;
	}
	return (str);
}
/*
int main()
{
	char str[] = "Hola, mon!";
	
	printf("Cadena original: %s\n", str);
	
	char *result = ft_strrev(str);
	
	printf("Cadena invertida: %s\n", result);
	
	return 0;
}
*/

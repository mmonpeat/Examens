/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:57:19 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/11 19:46:34 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <stdlib.h>

char **ft_split(char *str);
char *ret_words(char *str);
int count_words(char *str);
int ft_isSpace(char c);

/*
int main(void)
{
	char *str;

	str = "holiwiiis, com estas??";
	char **words = ft_split(str); // Emmagatzemar el resultat de ft_split
	if (words) 
	{
		int i = 0;
		while (words[i]) 
		{
			printf("word %d: %s\n", i, words[i]);
			free(words[i]); // Alliberar la memòria de cada paraula
			i++;
		}
		free(words); // Alliberar la memòria de l'array de paraules
	}
	return (0);
}*/

char **ft_split(char *str)
{
	int 	num_words;
	int		word_pos;
	char 	**array;

	num_words = count_words(str);
	word_pos = 0;
	array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	array[num_words] = 0;
	while (ft_isSpace(*str) == 1)
		++str;
	while (*str)
	{
		array[word_pos] = ret_words(str);
		++word_pos;
		while (*str && ft_isSpace(*str) == 0)
			str++;
		while (ft_isSpace(*str) == 1)
			str++;
	}
	return (array);
}

int count_words(char *str)
{
	int num_words = 0;
	while (ft_isSpace(*str) == 1)
		++str;
	while (*str)
	{
		++num_words;
		while (*str && ft_isSpace(*str) == 0)
			++str;
		while (ft_isSpace(*str) == 1)
			++str;
	}
	return (num_words);
}

int ft_isSpace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char *ret_words(char *str)
{
	int i;
	int len;
	char *word;

	i = 0;
	len = 0;
	while (str[len] && ft_isSpace(str[len]) == 0)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

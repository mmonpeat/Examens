/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:26:29 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 19:26:50 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int bol = 0;

    if (ac > 1)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        start = i;
        while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            while ((av[1][i] == ' ' && av[1][i + 1] == ' ') || (av[1][i] == '\t' && av[1][i + 1] == '\t'))
                i++;
            if (av[1][i] == ' ' || av[1][i] == '\t')
                bol = 1;
            write(1, &av[1][i], 1);
            i++;
        }
        if (bol != 0)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &av[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

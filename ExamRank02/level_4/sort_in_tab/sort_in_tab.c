/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:34:03 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/15 16:31:18 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void ft_swap(int *a, int *b);
void		sort_int_tab(int *tab, unsigned int size);

/*int main()
{
    int arr[] = {4, 2, 5, 1, 86, 7};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);

    sort_int_tab(arr, size);

    printf("Llista ordenada:\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    return 0;
}*/
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				swap;

	swap = 1;
	while (swap == 1)
	{
		i = 1;
		swap = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				ft_swap(&tab[i - 1], &tab[i]);
				swap = 1;
			}
			i++;
		}
	}
}

static void ft_swap(int *a, int *b)
{
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

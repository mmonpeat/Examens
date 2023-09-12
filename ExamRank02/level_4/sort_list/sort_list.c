/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:09:16 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/22 13:10:19 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;//apunta al inici de la llista
		}
		else
			lst = lst->next;
	}
	lst = tmp;//apunta al inici de la llista
	return (lst);//El que es retorna apunta al principi de la llista ordenada
}
/*
int cmp(int a, int b)
{
	return (a <= b);
}

int main()
{
    // Crear la llista desordenada
  t_list *list = malloc(sizeof(t_list));
    list->data = 42;

    t_list *node1 = malloc(sizeof(t_list));
    node1->data = 17;
    list->next = node1;

    t_list *node2 = malloc(sizeof(t_list));
    node2->data = 31;
    node1->next = node2;

    node2->next = NULL;

    // Mostrar la llista desordenada
    printf("Llista desordenada:\n");
    t_list *current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Ordenar la llista
    sort_list(list, cmp);

    // Mostrar la llista ordenada
    printf("Llista ordenada:\n");
    current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Alliberar la memòria de la llista
    current = list;
    while (current != NULL)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:24:22 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/20 15:27:30 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int		ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

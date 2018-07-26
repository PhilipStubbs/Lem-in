/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:22:34 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/26 17:57:08 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	setvalues(t_hold *node, t_room *room, int v)
{
	int		i;
	t_room	*tmp;

	i = 0;
	if (node->room->v != 0)
		return ;

	while (room->links[i] != NULL)
	{
		tmp = node->room;
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, room->links[i]) == 0) //&& tmp->v != 0)
			{
				// printf("[%s]\n", tmp->name);
				if (tmp->v == 0)
					tmp->v = v;
				setvalues(node, tmp, v +1);
			}
			tmp = tmp->next;
		}
		i++;
	}
	

}

void	findpath(t_hold *node)
{
	t_room	*list;
	t_room	*current;
	// t_room	*start;
	int		count;
	// int		i;

	list = node->room;

	while (list->next != NULL)
		list = list->next;
	current = list;
	count = 1;
	current->v = count;
	setvalues(node, current, count);
}


	// while (ft_strcmp(current->name, node->start->name) != 0)
	// {
		// list = node->room;
		// i = 0;
		// while (current->links[i] != NULL)
		// {
		// 	prelink = node->room;
		// 	while (ft_strcmp(prelink->name, current->links[i]) != 0 && prelink->next != NULL)
		// 	{
		// 		prelink = prelink->next;
		// 	}
		// 	prelink->v = count + 1;
		// 	i++;
		// }
		// count++;
		// while (ft_strcmp(list->name, current->links[0]) != 0 && list->next != NULL)
		// {
		// 	list = list->next;
		// }
		// current = list;
		
		// printf("[%s]\n", current->name);
	// }
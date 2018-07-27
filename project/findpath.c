/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:22:34 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/27 18:23:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	setvalues(t_hold *node, t_room *room, int v)
{
	int		i;
	t_room	*lst;
	t_room	*future;

	i = 0;
	if (node->room->v != 0)
		return ;
	// if (room->v == 0)
	// {
	// 	room->v = v;
	// 	v++;
	// }
	future = NULL;
	while (room->links[i])
	{
		lst = node->room;
		while (ft_strcmp(lst->name, room->links[i]) != 0)
				lst = lst->next;
		if (lst->v == 0)
		{
			lst->v = v + 1;
			if (!(future))
				future = lst;
		}
		i++;
	}
	setvalues(node, future, v);




	// while (room->links[i] != NULL)
	// {
	// 	tmp = node->room;
	// 	while (tmp->next != NULL)
	// 	{
	// 		if (ft_strcmp(tmp->name, room->links[i]) == 0 && tmp->v == 0)
	// 		{
	// 			if (tmp->v == 0)
	// 				tmp->v = room->v + 1;
	// 			// if (tmp->next == NULL && room->links[i + 1] == NULL)
	// 				setvalues(node, tmp, v +1);
	// 		}
	// 		tmp = tmp->next;
	// 	}
	// 	i++;
	// }
}

void	findpath(t_hold *node)
{
	t_room	*list;
	t_room	*current;
	int		count;

	list = node->room;

	while (list->next != NULL)
		list = list->next;
	current = list;
	count = 1;
	current->v = count;
	setvalues(node, current, count);
}

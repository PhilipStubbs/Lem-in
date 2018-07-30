/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:22:34 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/30 08:15:10 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		checkstart(t_hold *node)
{
	int		i;
	t_room	*lst;

	i = 0;
	while (node->room->links[i])
	{
		lst = node->room;
		while (ft_strcmp(lst->name, node->room->links[i]) != 0)
			lst = lst->next;
		if (lst->v != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	setvalues(t_hold *node, t_room *room, int v)
{
	int		i;
	t_room	*lst;
	t_room	*future;

	i = 0;
	if (node->room->v != 0)
		return ;
	future = NULL;
	while (room->links[i])
	{
		lst = node->room;
		while (ft_strcmp(lst->name, room->links[i]) != 0 && lst != NULL)
			lst = lst->next;
		if (lst->v == 0)
		{
			lst->v = v + 1;
			if (!(future))
				future = lst;
		}
		i++;
	}
	if (checkstart(node) == 0)
		setvalues(node, future, v + 1);
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

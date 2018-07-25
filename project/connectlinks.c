/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectlinks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:00:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 14:43:19 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	connectstart(t_hold *node)
{
	node->room->name =  ft_strdup(node->start->name);
	node->room->x = node->start->x;
	node->room->y = node->start->y;
}

void	connectend(t_hold *node)
{
	t_room *enpoint;
	t_room *list;

	list = node->room;
	enpoint = (t_room*)ft_memalloc(sizeof(t_room));
	enpoint->name = ft_strdup(node->end->name);
	enpoint->x = node->end->x;
	enpoint->y = node->end->y;
	enpoint->next = NULL;
	while (list->next != NULL)
		list = list->next;
	printf("[%s]\n", list->name);
	list->next = enpoint;
	list = list->next;
	printf("[%s]\n", list->name);

	
}

void	connectlinks(t_hold *node)
{
	if (node->ants == 0 || node->start == NULL || node->end == NULL)
		destroyerror(&node);
	connectstart(node);
	connectend(node);
}

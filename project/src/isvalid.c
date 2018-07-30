/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:21:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/30 08:28:41 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isvalid(t_hold *node)
{
	t_room *tmp;

	tmp = node->room;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->name, node->start->name) == 0)
		{
			if (tmp->links[0] == NULL)
				return (0);
		}
		if (ft_strcmp(tmp->name, node->end->name) == 0)
		{
			if (tmp->links[0] == NULL)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

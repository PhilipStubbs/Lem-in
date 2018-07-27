/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:53:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/27 13:16:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	moveem(t_hold *node, char *str)
// {

// }

void	moveants(t_hold *node)
{
	t_room	*tmp;
	t_room	*lst;
	t_room	*future;
	int		score;
	int		i;

	tmp = node->room;
	
	while (tmp->v != 1)
	{
		i = 0;
		score = INT_MAX;
		while (tmp->links[i])
		{
			lst = node->room;
			while (ft_strcmp(lst->name, tmp->links[i]) != 0)
				lst = lst->next;
			// printf("[%s]\n", l);
			if (lst->v < score && lst->v != 0 && ft_strcmp(tmp->name, tmp->links[i]) != 0)
			{
				score = lst->v;
				future = lst;
			}
			i++;
		}
		tmp = future;
		// printf("[%s]\n", tmp->name);
	}
}
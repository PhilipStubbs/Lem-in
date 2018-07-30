/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:53:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/30 08:29:23 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	creatpath(t_hold *node, char *str)
{
	char	*tmp;

	if (!node->path)
	{
		node->path = ft_strdup(str);
		return ;
	}
	tmp = ft_strdup(node->path);
	free(node->path);
	node->path = ft_strmerge(tmp, str);
	free(tmp);
}

void	moveantsbody(int *score, t_room **future, t_room *lst)
{
	if (lst->v < *score && lst->v != 0)
	{
		*score = lst->v;
		*future = lst;
	}
}

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
			moveantsbody(&score, &future, lst);
			i++;
		}
		tmp = future;
		creatpath(node, tmp->name);
	}
	moveem(node);
	ft_putchar('\n');
}

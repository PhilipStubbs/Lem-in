/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:53:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/28 11:00:27 by pstubbs          ###   ########.fr       */
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
	// if (ft_strcmp(str, node->end->name) == 0)
	// 	node->ants--;
}

void	moveantsbody(int *score, t_room **future, t_room *lst)
{
	if (lst->v < *score && lst->v != 0)
	{
		*score = lst->v;
		*future = lst;
	}
}

void	moveem(t_hold *node)
{
	char	**list;
	int		i;
	int		size;
	int		totalants;
	int		finishants;
	int		curant;
	int		turn;
	int		cturn;

	list = ft_split(node->path);
	free(node->path);
	size = doublesize(list);

	/*
	have max of size turns per a row;
	*/

	totalants = node->ants;
	finishants = 0;
	turn = 1;
	while (finishants < node->ants)
	{
		i = 0;
		curant = finishants + 1;
		cturn = turn;
		while ((list[i] || curant < node->ants -1) && cturn > 0 )
		{
			ft_putchar('L');
			ft_putnbr(curant);
			ft_putchar('-');
			ft_putstr(list[i]);
			if (ft_strcmp(list[i], node->end->name) == 0)
				finishants++;
			i++;
			curant++;
			cturn--;
		}
		turn++;
		ft_putchar('\n');
	}
	deldouble(&list);
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
	printf("[%s]\n", node->path);
	moveem(node);
}
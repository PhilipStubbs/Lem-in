/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:53:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/27 18:59:42 by pstubbs          ###   ########.fr       */
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
	int		count;
	int		i;
	int		turn;

	list = ft_split(node->path);
	free(node->path);
	count = 1;
	turn = 1;
	while (count <=node->ants)
	{
		i = 0;
		while (list[i] && i < turn)
		{
			ft_putchar('L');
			ft_putnbr(count);
			ft_putchar('-');
			ft_putstr(list[i]);
			ft_putchar(' ');
			i++;
		}
		turn++;
		ft_putchar('\n');
		if (list[i] == NULL || list[i + 1] == NULL)
			count++;
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
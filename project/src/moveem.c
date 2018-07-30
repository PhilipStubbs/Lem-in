/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:18:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/30 08:26:48 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		finished(int *list, int ants, int max)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < ants)
	{
		if (list[i] == max)
			ret++;
		i++;
	}
	return (ret);
}

int		moveembodybody(int *antlist, int ant, int size, int current)
{
	if (antlist[ant] < size && current > 0)
	{
		antlist[ant] = antlist[ant] + 1;
		return (1);
	}
	return (0);
}

void	moveembody(t_hold *node, char **list, int *antlist, int size)
{
	int	ant;
	int turns;
	int	current;
	int	finishants;

	finishants = 0;
	turns = 1;
	while (finishants < node->ants)
	{
		ant = finishants;
		current = turns;
		while (current > 0 && ant < node->ants)
		{
			current--;
			if (moveembodybody(antlist, ant, size, current) == 1)
				writemove(ant, list[antlist[ant] - 1]);
			ant++;
		}
		if (turns <= size)
			turns++;
		finishants = finished(antlist, node->ants, size);
		if (antlist[0] != 0)
			ft_putchar('\n');
	}
}

void	moveem(t_hold *node)
{
	char	**list;
	int		*antlist;
	int		size;

	antlist = (int*)ft_memalloc(sizeof(int) * node->ants);
	list = ft_split(node->path);
	free(node->path);
	size = doublesize(list);
	moveembody(node, list, antlist, size);
	free(antlist);
	deldouble(&list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:53:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/29 09:57:41 by pstubbs          ###   ########.fr       */
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

void	writemove(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant+1);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	printints(int *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("[%d | ", list[i++]);
	printf("\n");
}

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
			if(antlist[ant] < size  && current > 0)
			{
				antlist[ant] = antlist[ant] + 1;
				writemove(ant, list[antlist[ant]-1]);
				// if (antlist[ant] == size)
				// 	finishants++;
			}
			ant++;
		}
		ft_putchar('\n');
		if (turns <= size)
			turns++;
		finishants = finished(antlist, node->ants, size);
		// if (fins)
		// printf("[finished %d]\n", finishants);

		// printints(antlist, node->ants);

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
	printf("Path[%s]\n", node->path);
	moveem(node);
}



	// while (finishants < node->ants)
	// {
	// 	i = 0;
	// 	// ant = finishants;
	// 	ant = 0;
	// 	current = turns;
	// 	printints(antlist, node->ants - deletethis);
	// 	while (current > 0 && list[i])
	// 	{
	// 		if (antlist[ant - 1] == size && antlist[ant] + 1 == size)
	// 		{
	// 			writemove(ant, list[i]);
	// 			antlist[ant] = size;
	// 		}
	// 		// if ((ant == 0 || antlist[ant - 1] > (antlist[ant] + 1)))
	// 		// {
	// 		if (antlist[ant] <= size)
	// 		{
	// 			if (ant == 0 && antlist[ant] >= antlist[ant + 1])
	// 			{
	// 				antlist[ant] = i;
	// 				writemove(ant, list[antlist[ant]]);
	// 			}
	// 			if (antlist[ant] < antlist[ant - 1] + 1)
	// 			{
	// 				antlist[ant] = i;
	// 				writemove(ant, list[antlist[ant]]);
	// 			}
	// 		}
	// 		// }
	// 		if (ft_strcmp(node->end->name, list[i]) == 0)
	// 			finishants++;
	// 		// if (antlist[finishants] == size)
	// 		// 	finishants++;
	// 		i++;
	// 		if (antlist[ant] > antlist[ant+1])
	// 			ant++;
	// 		current--;
	// 	}
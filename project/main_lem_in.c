/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:31:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/26 17:55:28 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printlinks(t_hold *node)
{
	t_room	*tmp;
	int		i;

	tmp = node->room;
	while (tmp != NULL)
	{
		i = 0;
		printf("   Name [%s]\n", tmp->name);
		while (tmp->links[i] != NULL)
		{
			printf("	i %d | links [%s]\n", i, tmp->links[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

void	printlist(t_hold *node)
{
	t_room	*tmp;

	tmp = node->room;
	while (tmp != NULL)
	{
		printf("name %s | v %d \n", tmp->name, tmp->v);
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_hold *node;

	node = malloctime();
	getinfo(node);

	connectlinks(node);
	setlinks(node);

	findpath(node);
	printlist(node);
		// printf("[%s]\n", node->rawlinks);
	// printlinks(node);

	// dellst(&(node)->room);
	// destroy(&node);
}

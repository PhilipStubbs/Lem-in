/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:31:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 14:03:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printlinks(t_hold *node)
{
	t_room	*tmp;
	int	i;

	tmp = node->room;
	while (tmp->next != NULL)
	{	
		i = 0;
		while (tmp->links[i])
		{
			printf("name %s | i %d | link [%s]\n",tmp->name, i, tmp->links[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

void	printlist(t_hold *node)
{
	t_room	*tmp;

	tmp = node->room;
	while (tmp->next != NULL)
	{	
		printf("name %s \n",tmp->name);
		tmp = tmp->next;
	}
	printf("name %s \n",tmp->name);
}

int	main(void)
{
	t_hold *node;

	node = malloctime();
	getinfo(node);


	// printf("ANTS = %d\n", node->ants);
	// printf("START = %s\n", node->start->name);
	// printf("END = %s\n", node->end->name);
	// setlinks(node);
	// printf("%s x:%d y:%d\n", tmp->name, tmp->x, tmp->y);

	connectlinks(node);
	setlinks(node);

	printf("links = %s\n", node->rawlinks);
	printf("Totalrooms = %d\n", node->totalrooms);
	printlist(node);
	// printlinks(node);
	// dellst(&(node)->room);
	// destroy(&node);
}

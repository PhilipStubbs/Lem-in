/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:31:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/24 18:39:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hold *node;

	node = malloctime();
	getinfo(node);


	// printf("ANTS = %d\n", node->ants);
	// printf("START = %s\n", node->start->name);
	// printf("END = %s\n", node->end->name);
	// t_room *tmp = node->room;
	// while (tmp != NULL)
	// {
	// 	printf("%s x:%d y:%d\n", tmp->name, tmp->x, tmp->y);
	// 	tmp = tmp->next;
	// }
	printf("Totalrooms = %d\n", node->totalrooms);
	dellst(&(node)->room);
	destroy(&node);
}

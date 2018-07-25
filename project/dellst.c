/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:41:06 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 13:56:25 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dellst(t_room **lst)
{	
	t_room *tmp;
	int count;
	
	count = 0;
	while ((*lst)->next != NULL)
	{
		count++;
		write(1, "p\n", 2);
		tmp = (*lst);
		printf("%s\n", tmp->name);
		(*lst) = (*lst)->next;
		free(tmp->name);
		deldouble(&(tmp)->links);
		// free(tmp->name);
		free(tmp);
	}
	tmp = (*lst);
	free(tmp->name);
	// free(tmp);
	// free((*lst));
	printf("[%d]", count);
}


		// while ((*alst) != NULL)
		// {
		// 	del((*alst)->content, (*alst)->content_size);
		// 	free(*alst);
		// 	(*alst) = (*alst)->next;
		// }
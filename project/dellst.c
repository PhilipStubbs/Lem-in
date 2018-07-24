/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:41:06 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/24 10:54:15 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dellst(t_room **lst)
{

	while ((*lst)->next != NULL)
	{
		write(1, "x\n", 2);
		(*lst) = (*lst)->next;
		free((*lst)->name);
		write(1, "x\n", 2);
		free((*lst));
	}
}


		// while ((*alst) != NULL)
		// {
		// 	del((*alst)->content, (*alst)->content_size);
		// 	free(*alst);
		// 	(*alst) = (*alst)->next;
		// }
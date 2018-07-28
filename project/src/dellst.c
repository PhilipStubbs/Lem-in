/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:41:06 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/28 09:39:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dellst(t_room **lst)
{
	t_room *tmp;

	while ((*lst)->next != NULL)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp->name);
		free(tmp);
	}
}

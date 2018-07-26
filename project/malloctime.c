/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloctime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:29:34 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/26 11:16:25 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hold	*malloctime(void)
{
	t_hold	*ret;

	ret = (t_hold*)ft_memalloc(sizeof(t_hold));
	ret->room = (t_room*)ft_memalloc(sizeof(t_room));
	ret->room->x = 0;
	ret->room->y = 0;
	ret->room->v = 0;
	ret->room->next = NULL;
	ret->totalrooms = 0;
	ret->ants = 0;
	return (ret);
}

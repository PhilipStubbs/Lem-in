/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 08:23:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/26 08:24:11 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		listsize(t_room *lst)
{
	int		count;
	t_room	*tmp;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

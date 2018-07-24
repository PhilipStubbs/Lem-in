/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:07 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/24 12:19:16 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	destroy(t_hold **node)
{
	free((*node)->rawstr);
	free((*node)->str);
	// free((*node)->start->name);
	// free((*node)->start);
	if ((*node)->room)
		dellst(&(*node)->room);
	if ((*node)->start)
	{
		free((*node)->start->name);
		free((*node)->start);
	}
	if ((*node)->end)
	{
		free((*node)->end->name);
		free((*node)->end);
	}
	// free((*node)->room);
	free(*node);
	exit(1);
}

void	destroyerror(t_hold **node)
{
	free((*node)->rawstr);
	free((*node)->str);
	dellst(&(*node)->room);
	if ((*node)->start != NULL)
	{
		free((*node)->start->name);
		free((*node)->start);
	}
	if ((*node)->end != NULL)
	{
	free((*node)->end->name);
	free((*node)->end);
	}
	// free((*node)->room);
	free(*node);
	ERROR;
	exit(1);
}

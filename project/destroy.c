/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:07 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 11:45:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	destroy(t_hold **node, char **str)
{
	if ((*str))
		free(*str);
	free((*node)->room);
	free(*node);
	exit(1);
}

void	destroyerror(t_hold **node, char **str)
{
	if (*(str))
		free(*str);
	free((*node)->room);
	free(*node);
	ERROR;
	exit(1);
}

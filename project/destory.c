/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:51:07 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 10:04:38 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	destory(t_hold **node)
{
	free((*node)->room);
	free(*node);
	exit(1);
}

void	destoryerror(t_hold **node)
{
	free((*node)->room);
	free(*node);
	ERROR;
	exit(1);
}

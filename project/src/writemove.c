/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:12:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/30 08:29:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	writemove(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant + 1);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

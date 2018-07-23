/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:31:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 11:40:50 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hold *node;
	char *str;

	get_next_line(0, &str);
	node = malloctime();
	getinfo(node, str);

	// str = NULL;
	destory(&node, &str);
}

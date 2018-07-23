/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 10:12:41 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isstart(char *str)
{
	if (ft_strstr(str, "start") == NULL)
		return (0);
	return (1);
}

int		antamount(t_hold *node, char *str)
{
	int	amount;
	int	i;

	i = 0;
	if (isstart == 1)
		destoryerror(&node);
	while (i < 10)
	{
		if (ft_strstr(str, itoa(i)) != NULL)
			break ;
		if (i == 9 && ft_strstr(str, itoa(i)) == NULL)
			destoryerror(&node);
		i++;
	}
	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
		i++;
	node->ants = atol(str + i);
	return (amount);
}

int		getinfo(t_hold *node, char *str)
{
	char	*str;

	get_next_line(1, &str);
	antamount(node, str);
	return (1);
}

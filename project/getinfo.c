/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 10:23:17 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isstart(char *str)
{
	if (ft_strstr(str, "start"))
		return (0);
	if (ft_strstr(str, "start"))
		return (1);
	return (-1);
}

void	antamount(t_hold *node, char *str)
{
	int	i;

	i = 0;
	if (isstart == 0)
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
}

void	startroom(t_hold *node, char *str)
{
	while (isstart(str) == -1)
	{
		get_next_line(1, &str);
		if (isstart(str) == 1)
			destoryerror(&node);
	}
	node->start = ft_strdup(str);
}

int		getinfo(t_hold *node, char *str)
{
	char	*str;

	get_next_line(1, &str);
	antamount(node, str);
	startroom(node, str);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 11:41:18 by pstubbs          ###   ########.fr       */
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
	if (isstart(str) == 0)
		destoryerror(&node, &str);
	while (i < 10)
	{
		if (ft_strstr(str, ft_itoa(i)) != NULL)
			break ;
		if (i == 9 && ft_strstr(str, ft_itoa(i)) == NULL)
			destoryerror(&node, &str);
		i++;
	}
	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
		i++;
	write(1, "OUT\n", 4);
	node->ants = atol(str + i);
}

void	startroom(t_hold *node, char *str)
{
	while (isstart(str) == -1)
	{
		get_next_line(0, &str);
		if (isstart(str) == 1)
		{
			printf("inside starroom");
			destoryerror(&node, &str);
		}
	}
	node->start = ft_strdup(str);
}

int		getinfo(t_hold *node, char *str)
{
	antamount(node, str);
	printf("[%s]\n", str);
	startroom(node, str);
	return (1);
}

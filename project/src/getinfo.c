/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/29 16:58:56 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		findants(t_hold *node)
{
	int		i;
	char	*ret;

	i = 0;
	while (node->rawstr[i])
	{
		if (ft_isdigit(node->rawstr[i]) == 0)
			return (0);
		i++;
	}
	node->ants = atol(node->rawstr);
	get_next_line(0, &(ret));
	ft_strcpy(node->rawstr, ret);
	free(ret);
	return (1);
}

int		islink(char *str)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '-')
		{
			if ((ft_isprint(str[i - 1]) == 1 && ft_isprint(str[i + 1]) == 1))
			{
				return (2);
			}
		}
		i++;
	}
	return (0);
}

void	savelink(t_hold *node)
{
	char	*tmp;
	int		flag;

	flag = 0;
	if (!(node->rawlinks))
	{
		node->rawlinks = ft_strdup(node->rawstr);
		flag = 1;
	}
	if (flag == 0 && ft_strcmp(node->rawlinks, "") != 0)
	{
		tmp = ft_strmerge(node->rawlinks, node->rawstr);
		free(node->rawlinks);
		node->rawlinks = tmp;
	}
}

void	findrooms(t_hold *node)
{
	if (isstart(node->rawstr) == 0)
		setstart(node);
	else if (isstart(node->rawstr) == 1)
		setend(node);
	else if (islink(node->rawstr) == 2)
		savelink(node);
	else if (isroom(node->rawstr) == 3)
		setroom(node);
}

int		getinfo(t_hold *node)
{
	int		ret;
	int		count;

	count = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(0, &(node->rawstr));
		if (count == 0)
			if (findants(node) == 0)
				return (0);
		findrooms(node);
		count++;
		free(node->rawstr);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startandend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 09:37:24 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/28 09:38:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isstart(char *str)
{
	if (ft_strstr(str, "#start"))
		return (0);
	else if (ft_strstr(str, "#end"))
		return (1);
	return (-1);
}

void	setstart(t_hold *node)
{
	int		i;
	int		spacecount;
	char	**list;

	i = 0;
	spacecount = 0;
	node->totalrooms++;
	get_next_line(0, &(node->rawstr));
	list = ft_split(node->rawstr);
	node->start = (t_room*)ft_memalloc(sizeof(t_room));
	node->start->next = NULL;
	while (node->rawstr[i])
	{
		if ((ft_isdigit(node->rawstr[i]) == 0
		&& ft_isspace(node->rawstr[i]) == 0 && ft_isalpha(node->rawstr[i]) == 0)
		|| spacecount > 2)
			destroyerror(&node);
		if (ft_isspace(node->rawstr[i]) == 1)
			spacecount++;
		i++;
	}
	node->start->name = ft_strdup(list[0]);
	node->start->x = ft_atoi(list[1]);
	node->start->y = ft_atoi(list[2]);
	deldouble(&list);
}

void	setend(t_hold *node)
{
	int		i;
	int		spacecount;
	char	**list;

	i = 0;
	spacecount = 0;
	node->totalrooms++;
	get_next_line(0, &(node->rawstr));
	list = ft_split(node->rawstr);
	node->end = (t_room*)ft_memalloc(sizeof(t_room));
	node->end->next = NULL;
	while (node->rawstr[i])
	{
		if ((ft_isdigit(node->rawstr[i]) == 0
		&& ft_isspace(node->rawstr[i]) == 0 && ft_isalpha(node->rawstr[i]) == 0)
		|| spacecount > 2)
			destroyerror(&node);
		if (ft_isspace(node->rawstr[i]) == 1)
			spacecount++;
		i++;
	}
	node->end->name = ft_strdup(list[0]);
	node->end->x = ft_atoi(list[1]);
	node->end->x = ft_atoi(list[2]);
	deldouble(&list);
}

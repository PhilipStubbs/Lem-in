/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 09:35:50 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/28 09:36:54 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isroom(char *str)
{
	char	**list;
	int		size;

	list = ft_split(str);
	size = 0;
	while (list[size] != NULL)
		size++;
	deldouble(&list);
	if (size != 3)
		return (-1);
	return (3);
}

void	setroom(t_hold *node)
{
	t_room	*tmp;
	t_room	*lst;
	char	**info;

	node->totalrooms++;
	info = ft_split(node->rawstr);
	lst = node->room;
	tmp = (t_room*)ft_memalloc(sizeof(t_room));
	tmp->name = ft_strdup(info[0]);
	tmp->x = (ft_atoi(info[1]));
	tmp->y = (ft_atoi(info[2]));
	tmp->v = 0;
	tmp->next = NULL;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = tmp;
	lst = lst->next;
	deldouble(&info);
}

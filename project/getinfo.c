/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/24 13:50:20 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isroom(char *str)
{
	int		space;
	int		i;

	space = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (space != 2)
		return (-1);
	return (3);
}

int		isstart(char *str)
{

	if ((ft_strstr(str, "start")) && (ft_strstr(str, "#")))
		return (0);
	else if (ft_strstr(str, "end") && ft_strstr(str, "#"))
		return (1);
	return (-1);
}

void	findants(t_hold *node)
{
	int		i;
	char	*ret;

	i = 0;
	while (node->rawstr[i])
	{
		if (ft_isdigit(node->rawstr[i]) == 0)
			destroyerror(&node);
		i++;
	}
	node->ants = atol(node->rawstr);
	get_next_line(0, &(ret));
	ft_strcpy(node->rawstr, ret);
	free(ret);
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
	tmp->x = (atoi(info[1]));
	tmp->y = (atoi(info[2]));
	tmp->next = NULL;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = tmp;
	deldouble(&info);

}

void	findrooms(t_hold *node)
{
	if (isstart(node->rawstr) == 0)
	{
		setstart(node);
	}
	else if (isstart(node->rawstr) == 1)
	{
		setend(node);
	}
	// else if (islink(node->rawstr) == 2)
		// setlink(node);
	if (isroom(node->rawstr) == 3)
	{
		setroom(node);
	}
}

void	connectlinks(t_hold *node)
{
	t_room *stpoint;
	t_room *enpoint;

	if (node->ants == 0 || node->start == NULL || node->end == NULL)
		destroyerror(&node);
	stpoint = node->start;
	enpoint = node->end;
	stpoint->next = node->room;
	node->room = stpoint;
}

int		getinfo(t_hold *node)
{
	int		ret;
	int		count;
	char	*str;

	count = 0;
	(void)node;
	// free(node->rawstr);
	ret = 1;
	node->rawstr = (char*)ft_memalloc(sizeof(char) * 10);
	// ft_strclr(node->rawstr);
	// ret = get_next_line(0, &str);
	// while (ret != 0 && count <= 11)
	// {
		// ret = get_next_line(0, &str);

		// free(str);

		
		// ret = get_next_line(0, &str);
		// ft_strcpy(node->rawstr, str);
		// free(str);

		// if (count == 0)
		// 	findants(node);
		// findrooms(node);
		count++;
		
	// 	ft_memdel((void**)&str);
	// 	ft_strclr(node->rawstr);
	// }
	printf("count %d", count);
	// connectlinks(node);
	// free(node->rawstr);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlinks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 09:57:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/27 10:34:38 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	setforwardlinks(int num, char **list, t_room *tmp)
{
	int		i;
	int		n;
	int		l;

	n = 0;
	while (n < num)
	{
		l = 0;
		while (list[l])
		{
			i = 0;
			while (list[l][i] != '-' && list[l][i] != '\0')
				i++;
			if (ft_strncmp(tmp->name, list[l], i) == 0)
			{
				tmp->links[n] = ft_strsub(list[l], i + 1, ft_strlen(list[l]));
				n++;
			}
			l++;
		}
	}
}

int		matchingforwardlink(char *name, char **list)
{
	int		count;
	int		i;
	int		l;

	l = 0;
	count = 0;
	while (list[l] != NULL)
	{
		i = 0;
		while (list[l][i])
		{
			if (list[l][i] == '-')
			{
				if (ft_strncmp(name, list[l], i) == 0)
				{
					count++;
				}
			}
			i++;
		}
		l++;
	}
	return (count);
}

int		matchingpreviouslink(char *name, char **list)
{
	int		count;
	int		i;
	int		l;
	int		len;

	l = 0;
	count = 0;
	while (list[l] != NULL)
	{
		i = 0;
		len = ft_strlen(list[l]);
		while (list[l][i])
		{
			if (list[l][i] == '-')
			{
				if (ft_strncmp(name, list[l] + i + 1, len - i) == 0)
				{
					count++;
				}
			}
			i++;
		}
		l++;
	}
	return (count);
}

void	setpreviouslinks(int num, int n, char **list, t_room *tmp)
{
	int		i;
	int		l;

	while (n < num)
	{
		l = 0;
		while (list[l])
		{
			i = 0;
			while (list[l][i] != '-' && list[l][i] != '\0')
				i++;
			if (ft_strncmp(tmp->name, list[l] + i + 1, ft_strlen(list[l]) - i)
			== 0)
			{
				tmp->links[n] = ft_strsub(list[l], 0, i);
				n++;
			}
			l++;
		}
	}
	tmp->links[num] = NULL;
}

int	setlinks(t_hold *node)
{
	t_room	*tmp;
	char	**list;
	int		num;
	int		pnum;

	if (listsize(node->room) <= 2)
	{
		printf("[HERE]\n");
		return (0);
	}
	list = ft_split(node->rawlinks);
	tmp = node->room;
	while (tmp != NULL)
	{
		num = matchingforwardlink(tmp->name, list);
		pnum = matchingpreviouslink(tmp->name, list);
		tmp->links = (char**)ft_memalloc(sizeof(char*) * (num + pnum + 1));
		setforwardlinks(num, list, tmp);
		setpreviouslinks(num + pnum, num, list, tmp);
		tmp = tmp->next;
	}
	deldouble(&list);
	free(tmp);
	return (1);
}

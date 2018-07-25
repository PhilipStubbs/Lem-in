/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlinks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 09:57:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 10:43:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		matchinglink(char *name, char **list)
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

void	setlinks(t_hold *node)
{
	t_room	*tmp;
	char	**list;
	int		num;
	// int		i;
	// int		start;
	// int		l;

	list = ft_split(node->rawlinks);
	tmp = node->room;
	while (tmp->next != NULL)
	{
		num = matchinglink(tmp->name, list);
		printf("[%s] %d\n",tmp->name, num);
		tmp = tmp->next;
	}
	deldouble(&list);
	free(tmp);
}



// void	setlinks(t_hold *node)
// {
// 	t_room	*tmp;
// 	char	*tmpname;
// 	char	**list;
// 	int		i;
// 	int		l;

// 	tmp = node->room;
// 	list = ft_split(node->rawlinks);
// 	l = 0;
// 	while (tmp->next != NULL)
// 	{
// 		l = 0;
// 		while (list[l])
// 		{
// 			i = 0;
// 			while (list[l][i] != '-')
// 			{
// 				i++;
// 			}
// 			l++;
// 			tmpname = ft_strsub(list[l],0 , i);
// 			// tmpname[i] = '\0';
// 			// printf("[%zu]\n", ft_strlen(tmpname));
// 			// if (ft_strcmp(tmp->name, tmpname) == 0)
// 			// 	printf("[%s]\n", tmpname);
// 			free(tmpname);
// 		}
// 		tmp = tmp->next;
		
// 	}
// 	deldouble(&list);
// 	free(tmp);
// }
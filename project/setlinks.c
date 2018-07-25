/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlinks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 09:57:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 13:42:08 by pstubbs          ###   ########.fr       */
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

int		doublesize(char **list)
{
	int	size;

	size = 0;
	while (list[size])
		size++;
	return (size);
}

void	setlinks(t_hold *node)
{
	t_room	*tmp;
	char	**list;
	int		num;
	int		i;
	int		n;
	// int		start;
	int		l;

	
	list = ft_split(node->rawlinks);
	tmp = node->room;
	while (tmp->next != NULL)
	{
		num = matchinglink(tmp->name, list);
		tmp->links = (char**)ft_memalloc(sizeof(char*) * num);
		// printf("name [%s] size [%d]\n",tmp->name, num);
		l = 0;
		n = 0;
		tmp->links[num] = NULL;
		while (n < num)
		{
			l = 0;
			while (list[l])
			{
				i = 0;
				while (list[l][i] != '-' && list[l][i] != '\0')
					i++;
				// printf("[%s]\n", list[l] + i + 1);
				if (ft_strncmp(tmp->name, list[l], i) == 0)
				{
					// tmp->links[n] = ft_strdup(list[l] + i + 1);
					tmp->links[n] = ft_strsub(list[l], i + 1, ft_strlen(list[l]));
					// printf("name %s | n %d | link [%s]\n",tmp->name, n, tmp->links[n]);
					n++;
				}
				l++;
			}
		}
		
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:06:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 18:20:07 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		isstart(char *str)
{
	if (ft_strstr(str, "start"))
		return (0);
	if (ft_strstr(str, "end"))
		return (1);
	return (-1);
}

void	findants(t_hold *node)
{
	int		i;

	i = 0;
	while (node->str[i])
	{
		if (ft_isdigit(node->str[i]) == 0)
			destroyerror(&node);
		i++;
	}
	node->ants = atol(node->str);
}

void	setstartend(t_hold *node, int se)
{
	int	i;
	int	spacecount;

	i = 0;
	spacecount = 0;
	get_next_line(0, &(node->str));
	while (node->str[i])
	{
		if ((ft_isdigit(node->str[i]) == 0 && ft_isspace(node->str[i]) == 0) ||
		spacecount > 2)
			destroyerror(&node);
		if (ft_isspace(node->str[i]) == 1)
		spacecount++;
		i++;
	}
	if (se == 0)
		node->start = ft_strdup(node->str);
	if (se == 1)
		node->end = ft_strdup(node->str);
}

void	findrooms(t_hold *node)
{
	if (isstart(node->str) == 0)
		setstartend(node, 0);
	if (isstart(node->str) == 1)
		setstartend(node, 1);
}

int		getinfo(t_hold *node)
{
	int		ret;
	int		count;
	
	count = 0;
	while((ret = get_next_line(0, &(node->str)) != 0))
	{
		if (count == 0)
			findants(node);
		findrooms(node);
		count++;
	}
	printf("ANTS = %d\n",node->ants);
	printf("START = %s\n",node->start);
	printf("END = %s\n",node->end);
	return (1);
}



// void	antamount(t_hold *node, char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (isstart(str) == 0)
// 		destoryerror(&node, &str);
// 	while (i < 10)
// 	{
// 		if (ft_strstr(str, ft_itoa(i)) != NULL)
// 			break ;
// 		if (i == 9 && ft_strstr(str, ft_itoa(i)) == NULL)
// 			destoryerror(&node, &str);
// 		i++;
// 	}
// 	i = 0;
// 	while (!(str[i] >= '0' && str[i] <= '9'))
// 		i++;
// 	write(1, "OUT\n", 4);
// 	node->ants = atol(str + i);
// }

// void	startroom(t_hold *node)
// {
// 	while (isstart(node->str) == -1)
// 	{
// 		get_next_line(0, node->str);
// 		if (isstart(node->str) == 1)
// 		{
// 			printf("inside starroom");
// 			destroyerror(&node);
// 		}
// 	}
// 	node->start = ft_strdup(node->str);
// }
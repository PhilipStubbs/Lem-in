/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:31:17 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/28 09:56:13 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printlinks(t_hold *node)
{
	t_room	*tmp;
	int		i;

	tmp = node->room;
	while (tmp != NULL)
	{
		i = 0;
		ft_putchar('\t');
		ft_putendl(tmp->name);
		while (tmp->links[i] != NULL)
		{
			ft_putstr("	i ");
			ft_putnbr(i);
			ft_putstr(" | links [");
			ft_putstr(tmp->links[i]);
			ft_putendl("]\n");
			// printf("	i %d | links [%s]\n", i, tmp->links[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

void	printlist(t_hold *node)
{
	t_room	*tmp;

	tmp = node->room;
	while (tmp != NULL)
	{
		printf("name %s | v %d \n", tmp->name, tmp->v);
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_hold *node;
	t_room *tmp;
	int		ret;

	node = malloctime();
	if ((ret = getinfo(node)) == 0)
		ERROR;
	if ((ret != 0) && (ret = connectlinks(node)) == 0)
		ERROR;
	if ((ret != 0) && (ret = setlinks(node)) == 0)
		ERROR;
	if ((ret != 0) && (ret = isvalid(node)) == 0)
		ERROR;
	if (ret != 0)
	{
		findpath(node);
		// printlist(node);
	// 	printf("ants[%d] [%s]\n",node->ants , node->rawlinks);
		// printlinks(node);
	}
	if (ret != 0)
		moveants(node);
	tmp = node->room;




	while (tmp != NULL)
	{
		deldouble(&(tmp->links));
		tmp = tmp->next;
	}
	tmp = node->room;


	
	destroy(&node);
}

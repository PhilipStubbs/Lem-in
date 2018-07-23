/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/23 11:45:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdio.h>

# define ERROR ft_putendl_fd("Error", 2);

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef	struct		s_hold
{
	t_room			*room;
	int				totalrooms;
	int				ants;
	char			*start;
	char			*end;
}					t_hold;

t_hold				*malloctime(void);
int					getinfo(t_hold *node, char *str);
void				destroy(t_hold **node, char **str);
void				destroyerror(t_hold **node, char **str);


#endif

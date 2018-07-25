/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/25 14:01:16 by pstubbs          ###   ########.fr       */
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
	char			**links;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef	struct		s_hold
{
	t_room			*room;
	t_room			*start;
	t_room			*end;
	int				totalrooms;
	int				ants;
	char			*rawstr;
	char			*str;
	char			*rawlinks;
}					t_hold;

t_hold				*malloctime(void);
int					getinfo(t_hold *node);
void				destroy(t_hold **node);
void				destroyerror(t_hold **node);
void				dellst(t_room **lst);
void 				deldouble(char ***str);

void				setlinks(t_hold *node);
void				connectlinks(t_hold *node);


#endif

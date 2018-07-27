/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/27 18:15:55 by pstubbs          ###   ########.fr       */
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
	int				v;
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
	char			*path;
	char			*rawstr;
	char			*str;
	char			*rawlinks;
}					t_hold;

t_hold				*malloctime(void);
void				destroy(t_hold **node);
void				destroyerror(t_hold **node);
void				dellst(t_room **lst);

int					getinfo(t_hold *node);
int					connectlinks(t_hold *node);
int					setlinks(t_hold *node);
int					listsize(t_room *lst);
int					isvalid(t_hold *node);

void				findpath(t_hold *node);
void				moveants(t_hold *node);

char				*ft_strmerge(char *s1, char *s2);
void				deldouble(char ***str);
int					doublesize(char **list);


#endif

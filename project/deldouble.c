/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deldouble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:56:32 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/24 12:59:48 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void deldouble(char ***str)
{
	int	i;

	i = 0;
	while (str[0][i] != NULL)
	{
		i++;
	}
	while (i >= 0)
	{
		free(str[0][i--]);
	}
	free(*str);
}


// void deldouble(char ***str)
// {
// 	int	i;

// 	i = 0;
// 	// while (str[0][i] != NULL)
// 	// {
// 	// 	i++;
// 	// }
// 	while (str[0][i])
// 	{
// 		i++;
// 		// free(str[0][i--]);
// 	}
// 	free(*str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:11:44 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 14:47:25 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_stk_add.c                                             |
**   |     ft_stk_add(9 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

t_stk		*ft_stk_add(t_stk **first, int nb)
{
	t_stk	*new;

	if (first == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(t_stk))))
		ft_error();
	new->nb = nb;
	new->next = *first;
	return (*first = new);
}

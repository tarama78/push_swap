/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:22:18 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 22:54:15 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_stk_get.c                                             |
**   |     ft_stk_get(13 lines)                                 |
**   |     ft_stk_get_pos(11 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

t_stk		*ft_stk_get(t_stk *first, int n)
{
	int		i;

	if (first == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if (first->next)
			first = first->next;
		else
			break ;
	}
	return (first);
}

int			ft_stk_get_pos(t_stk *first, int nb)
{
	int		i;

	i = 0;
	while (first)
	{
		if (first->nb == nb)
			return (i);
		i++;
		first = first->next;
	}
	return (-1);
}

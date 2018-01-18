/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:55:29 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 11:55:34 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_is_sort.c                                             |
**   |     ft_is_sort(22 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/


#include <push_swap.h>

int			ft_is_sort(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_b != NULL)
	{
		if (print)
			ft_printf("KO\n");
		return (0);
	}
	stk = a->stk_a;
	while (stk->next)
	{
		if (stk->nb >= stk->next->nb)
		{
			if (print)
				ft_printf("KO\n");
			return (0);
		}
		stk = stk->next;
	}
	if (print)
		ft_printf("OK\n");
	return (1);
}

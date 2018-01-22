/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:57:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 14:47:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_ss.c                                                  |
**   |     ft_sa(11 lines)                                      |
**   |     ft_sb(11 lines)                                      |
**   |     ft_ss(5 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

int			ft_sa(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_a == NULL || a->stk_a->next == NULL)
		return (1);
	stk = a->stk_a->next;
	a->stk_a->next = a->stk_a->next->next;
	stk->next = a->stk_a;
	a->stk_a = stk;
	if (print)
		ft_printf(SA"\n");
	return (1);
}

int			ft_sb(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_b == NULL || a->stk_b->next == NULL)
		return (1);
	stk = a->stk_b->next;
	a->stk_b->next = a->stk_b->next->next;
	stk->next = a->stk_b;
	a->stk_b = stk;
	if (print)
		ft_printf(SB"\n");
	return (1);
}

int			ft_ss(t_a *a, int print)
{
	ft_sa(a, 0);
	ft_sb(a, 0);
	if (print)
		ft_printf(SS"\n");
	return (1);
}

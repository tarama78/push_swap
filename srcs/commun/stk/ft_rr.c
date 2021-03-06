/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:40:22 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 14:47:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_rr.c                                                  |
**   |     ft_ra(13 lines)                                      |
**   |     ft_rb(13 lines)                                      |
**   |     ft_rr(5 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

int			ft_ra(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_a == NULL || a->stk_a->next == NULL)
		return (1);
	stk = a->stk_a;
	while (stk->next)
		stk = stk->next;
	stk->next = a->stk_a;
	a->stk_a = a->stk_a->next;
	stk->next->next = NULL;
	if (print)
		ft_printf(RA"\n");
	return (1);
}

int			ft_rb(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_b == NULL || a->stk_b->next == NULL)
		return (1);
	stk = a->stk_b;
	while (stk->next)
		stk = stk->next;
	stk->next = a->stk_b;
	a->stk_b = a->stk_b->next;
	stk->next->next = NULL;
	if (print)
		ft_printf(RB"\n");
	return (1);
}

int			ft_rr(t_a *a, int print)
{
	ft_ra(a, 0);
	ft_rb(a, 0);
	if (print)
		ft_printf(RR"\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:40:22 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 17:56:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_rr.c                                                  |
**   |     ft_ra(10 lines)                                      |
**   |     ft_rb(10 lines)                                      |
**   |     ft_rr(2 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

void		ft_ra(t_a *a)
{
	t_stk	*stk;

	if (a->stk_a == NULL || a->stk_a->next == NULL)
		return ;
	stk = a->stk_a;
	while (stk->next)
		stk = stk->next;
	stk->next = a->stk_a;
	a->stk_a = a->stk_a->next;
	stk->next->next = NULL;
}

void		ft_rb(t_a *a)
{
	t_stk	*stk;

	if (a->stk_b == NULL || a->stk_b->next == NULL)
		return ;
	stk = a->stk_b;
	while (stk->next)
		stk = stk->next;
	stk->next = a->stk_b;
	a->stk_b = a->stk_b->next;
	stk->next->next = NULL;
}

void		ft_rr(t_a *a)
{
	ft_ra(a);
	ft_rb(a);
}

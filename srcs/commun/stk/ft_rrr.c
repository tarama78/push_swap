/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:56:36 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 18:08:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_rrr.c                                                 |
**   |     ft_rra(10 lines)                                     |
**   |     ft_rrb(10 lines)                                     |
**   |     ft_rrr(2 lines)                                      |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

void		ft_rra(t_a *a)
{
	t_stk	*stk;

	if (a->stk_a == NULL || a->stk_a->next == NULL)
		return ;
	stk = a->stk_a;
	while (stk->next->next)
		stk = stk->next;
	stk->next->next = a->stk_a;
	a->stk_a = stk->next;
	stk->next = NULL;
}

void		ft_rrb(t_a *a)
{
	t_stk	*stk;

	if (a->stk_b == NULL || a->stk_b->next == NULL)
		return ;
	stk = a->stk_b;
	while (stk->next->next)
		stk = stk->next;
	stk->next->next = a->stk_b;
	a->stk_b = stk->next;
	stk->next = NULL;
}

void		ft_rrr(t_a *a)
{
	ft_rra(a);
	ft_rrb(a);
}

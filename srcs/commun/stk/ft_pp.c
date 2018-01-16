/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:15:32 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/16 11:46:20 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_pp.c                                                  |
**   |     ft_pa(12 lines)                                      |
**   |     ft_pb(12 lines)                                      |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

void		ft_pa(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_b == NULL)
		return ;
	stk = a->stk_b;
	a->stk_b = a->stk_b->next;
	stk->next = a->stk_a;
	a->stk_a = stk;
	a->sz_a++;
	a->sz_b--;
	if (print)
		ft_printf(PA"\n");
}

void		ft_pb(t_a *a, int print)
{
	t_stk	*stk;

	if (a->stk_a == NULL)
		return ;
	stk = a->stk_a;
	a->stk_a = a->stk_a->next;
	stk->next = a->stk_b;
	a->stk_b = stk;
	a->sz_a--;
	a->sz_b++;
	if (print)
		ft_printf(PB"\n");
}

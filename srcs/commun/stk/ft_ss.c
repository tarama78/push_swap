/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:57:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 17:39:59 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_ss.c                                                  |
**   |     ft_sa(8 lines)                                       |
**   |     ft_sb(8 lines)                                       |
**   |     ft_ss(2 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

void		ft_sa(t_a *a)
{
	t_stk	*stk;

	if (a->stk_a == NULL || a->stk_a->next == NULL)
		return ;
	stk = a->stk_a->next;
	a->stk_a->next = a->stk_a->next->next;
	stk->next = a->stk_a;
	a->stk_a = stk;
}

void		ft_sb(t_a *a)
{
	t_stk	*stk;

	if (a->stk_b == NULL || a->stk_b->next == NULL)
		return ;
	stk = a->stk_b->next;
	a->stk_b->next = a->stk_b->next->next;
	stk->next = a->stk_b;
	a->stk_b = stk;
}

void		ft_ss(t_a *a)
{
	ft_sa(a);
	ft_sb(a);
}

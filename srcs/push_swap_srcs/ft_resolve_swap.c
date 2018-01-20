/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:21:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/19 18:10:13 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_swap.c                                        |
**   |     ft_sort_int_2(25 lines)                              |
**   |     ft_sort_int(25 lines)                                |
**   |     ft_move_start(18 lines)                              |
**   |     ft_move_end(8 lines)                                 |
**   |     ft_sort_bloc(25 lines)                               |
**   |     ft_recurs(13 lines)                                  |
**   |     ft_resolve_swap(19 lines)                            |
**   | MEUUUU too many functions                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     \|/   \|/
**     |||   |||
*/

#include <push_swap.h>

static void	ft_sort_int_2(t_a *a)
{
	int		max;

	max = ft_max(a->stk_a->nb, ft_max(a->stk_a->next->nb,
				a->stk_a->next->next->nb));
	if (max == a->stk_a->next->next->nb)
	{
		if (a->stk_a->nb > a->stk_a->next->nb)
			ft_sa(a, 1);
		ft_pb(a, 1) && ft_pb(a, 1);
	}
	else if (max == a->stk_a->next->nb)
	{
		ft_pb(a, 1) && ft_sa(a, 1) && ft_pb(a, 1);
		if (a->stk_b->nb < a->stk_b->next->nb)
			ft_sb(a, 1);
	}
	else
	{
		ft_sa(a, 1) && ft_pb(a, 1);
		if (a->stk_a->nb > a->stk_a->next->nb)
			ft_sa(a, 1);
		if (ft_pb(a, 1) && a->stk_b->nb < a->stk_b->next->nb)
			ft_sb(a, 1);
	}
	ft_pb(a, 1);
}

static void	ft_sort_int(t_a *a, int sz_sort, t_inf inf)
{
	if (inf & DST_A)
	{
		if (a->stk_a->nb > a->stk_a->next->nb)
			ft_sa(a, 1);
		if ((sz_sort == 3) && (a->stk_a->next->nb > a->stk_a->next->next->nb))
		{
			ft_pb(a, 1);
			if (a->stk_a->nb > a->stk_a->next->nb)
				ft_sa(a, 1);
			ft_pa(a, 1);
			if (a->stk_a->nb > a->stk_a->next->nb)
				ft_sa(a, 1);
		}
	}
	else
	{
		if (sz_sort == 2)
		{
			if (a->stk_a->nb > a->stk_a->next->nb)
				ft_sa(a, 1);
			ft_pb(a, 1) && ft_pb(a, 1);
		}
		else
			ft_sort_int_2(a);
	}
}

static void	ft_recurs(t_a *a, int sz_sort, t_inf inf)
{
	int		sz1;
	int		sz2;

	if (sz_sort <= 3)
	{
		ft_sort_int(a, sz_sort, inf);
		return ;
	}
	sz1 = sz_sort >> 1;
	sz2 = ((sz_sort & 1) == 0) ? sz1 : sz1 + 1;
	ft_recurs(a, sz1, SRC_A | DST_B);
	ft_recurs(a, sz2, SRC_A | DST_A);
	ft_sort_bloc(a, sz_sort, inf);

}

void		ft_resolve_swap(t_a *a)
{
	int		end;
	t_stk	*stk;

	end = 0;
	stk = a->stk_a;
	if (stk->next == NULL)
		return ;
	while (stk->next && end == 0)
	{
		if (stk->nb > stk->next->nb)
			end = 1;
		stk = stk->next;
	}
	if (end == 0)
		return ;
	if (a->sz_list <= 25)
		ft_resolve_small(a);
	else
		ft_recurs(a, a->sz_list, SRC_A | DST_A);
}

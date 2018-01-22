/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:23:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 11:35:20 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_sort_bloc.c                                           |
**   |     ft_move_start(18 lines)                              |
**   |     ft_move_end(8 lines)                                 |
**   |     ft_sort_bloc(25 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

static void	ft_move_start(t_a *a, int sz, int *pos_sz1, t_inf inf)
{
	if (inf & DST_A)
	{
		while (sz > 0 && a->stk_b->nb > a->stk_a->nb)
		{
			ft_ra(a, 1);
			--sz;
			(*pos_sz1)++;
		}
	}
	else
	{
		while (sz > 0 && a->stk_a->nb < a->stk_b->nb)
		{
			ft_rb(a, 1);
			--sz;
			(*pos_sz1)++;
		}
	}
}

static void	ft_move_end(t_a *a, int *pos_sz1, t_inf inf)
{
	while (*pos_sz1 > 0)
	{
		if (inf & DST_A)
			ft_rra(a, 1);
		else
			ft_rrb(a, 1);
		(*pos_sz1)--;
	}
}

void		ft_sort_bloc(t_a *a, int sz_sort, t_inf inf)
{
	int		sz1;
	int		pos_sz1;
	int		sz2;

	pos_sz1 = 0;
	sz1 = sz_sort >> 1;
	sz2 = ((sz_sort & 1) == 0) ? sz1 : sz1++;
	ft_move_start(a, ((inf & DST_A) ? sz1 : sz2), &pos_sz1, inf);
	if (inf & DST_A)
		while (sz2 > 0)
			if (((a->stk_b->nb < a->stk_a->nb) && ((pos_sz1 == 0) ||
							(a->stk_b->nb > ft_stk_getlast(a->stk_a)->nb))) ||
					(pos_sz1 == sz1))
				ft_pa(((++sz1) ? a : a), ((--sz2) ? 1 : 1));
			else
				ft_rra(a, ((--pos_sz1) ? 1 : 1));
	else
		while (sz1 > 0)
			if (((a->stk_a->nb > a->stk_b->nb) && ((pos_sz1 == 0) ||
							(a->stk_a->nb < ft_stk_getlast(a->stk_b)->nb))) ||
					(pos_sz1 == sz2))
				ft_pb(((--sz1) ? a : a), ((++sz2) ? 1 : 1));
			else
				ft_rrb(a, ((--pos_sz1) ? 1 : 1));
	ft_move_end(a, &pos_sz1, inf);
}

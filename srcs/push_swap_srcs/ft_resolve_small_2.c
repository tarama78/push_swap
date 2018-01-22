/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_small_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:21:08 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 11:35:20 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_small_2.c                                     |
**   |     ft_put_nb_a_first_1(21 lines)                        |
**   |     ft_put_nb_a_first_2(20 lines)                        |
**   |     ft_put_nb_a_first(20 lines)                          |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

static int	ft_put_nb_a_first_1(t_a *a, t_small *inf)
{
	int		i;

	i = -1;
	ft_get_min(a, &inf->min2, &inf->last_min2, &inf->inf);
	if (inf->inf & MIN_A)
	{
		inf->pos2 = ft_stk_get_pos(a->stk_a, inf->min2);
		if (inf->pos2 + 1 == inf->pos)
			while (++i < inf->pos2)
				ft_ra(a, 1);
		else if (inf->pos == 0 && inf->pos2 == a->sz_a - 1)
			ft_rra(a, 1);
		else
			return (1);
	}
	ft_sa(a, 1);
	ft_ra(a, 1);
	ft_ra(a, 1);
	inf->min = inf->min2;
	inf->last_min = inf->last_min2;
	return (0);
}

static int	ft_put_nb_a_first_2(t_a *a, t_small *inf)
{
	int		i;

	i = -1;
	ft_get_min(a, &inf->min2, &inf->last_min2, &inf->inf);
	if (inf->inf & MIN_A)
	{
		inf->pos2 = ft_stk_get_pos(a->stk_a, inf->min2);
		if (inf->pos2 + 1 == inf->pos)
		{
			while (++i <= inf->pos2)
				ft_pb(a, 1);
			ft_ra(a, 1);
			ft_pa(a, 1);
			ft_ra(a, 1);
			inf->min = inf->min2;
			inf->last_min = inf->last_min2;
			return (0);
		}
	}
	return (1);
}

void		ft_put_nb_a_first(t_a *a, t_small *inf)
{
	int		i;

	inf->pos = ft_stk_get_pos(a->stk_a, inf->min);
	inf->min2 = inf->min;
	inf->last_min2 = inf->min2;
	i = -1;
	if (inf->pos < (a->sz_a >> 1))
	{
		if (ft_put_nb_a_first_1(a, inf) == 0)
			return ;
		while (++i <= inf->pos)
			ft_ra(a, 1);
	}
	else if (inf->pos < a->sz_a - 1)
	{
		if (ft_put_nb_a_first_2(a, inf) == 0)
			return ;
		while (++i < a->sz_a - inf->pos - 1)
			ft_rra(a, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:50:22 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 18:45:50 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_small.c                                       |
**   |     ft_get_min_stk(18 lines)                             |
**   |     ft_get_min(5 lines)                                  |
**   |     ft_put_nb_a_first(62 lines)                          |
**   |         MEUUUU too many lines                            |
**   |     ft_put_nb_a(8 lines)                                 |
**   |     ft_put_nb_b(13 lines)                                |
**   |     ft_resolve_small(19 lines)                           |
**   | MEUUUU too many functions                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

static void	ft_get_min_stk(t_a *a, t_ll *min, t_ll *last_min, t_inf_small *inf)
{
	t_stk	*stk;

	if (*inf & TEST_A)
		stk = a->stk_a;
	else
		stk = a->stk_b;
	while (stk)
	{
		if (stk->nb < *min && stk->nb > *last_min)
		{
			*min = stk->nb;
			if (*inf & TEST_A)
				*inf = (*inf | MIN_A) - ((*inf & MIN_B) == MIN_B) * MIN_B;
			else
				*inf = (*inf | MIN_B) - ((*inf & MIN_A) == MIN_A) * MIN_A;
		}
		stk = stk->next;
	}
}

static void	ft_get_min(t_a *a, t_ll *min, t_ll *last_min, t_inf_small *inf)
{
	*min = (t_ll)INT_MAX + 1;
	*inf = (*inf | TEST_A) - ((*inf & TEST_B) == TEST_B) * TEST_B;
	ft_get_min_stk(a, min, last_min, inf);
	*inf = (*inf | TEST_B) - ((*inf & TEST_A) == TEST_A) * TEST_A;
	ft_get_min_stk(a, min, last_min, inf);
}

static int	ft_put_nb_a_first_1(t_a *a, t_small *inf)
{
	int		i;

	i = -1;
	ft_get_min(a, &inf->min2, &inf->last_min2, &inf->inf);
	if (inf->inf & MIN_A)
	{
		inf->pos2 = ft_stk_get_pos(a->stk_a, inf->min2);
		if (inf->pos2 + 1 == inf->pos)
		{
			while (++i < inf->pos2)
				ft_ra(a, 1);
			ft_sa(a, 1);
			ft_ra(a, 1);
			ft_ra(a, 1);
			inf->min = inf->min2;
			inf->last_min = inf->last_min2;
		}
		else if (inf->pos == 0 && inf->pos2 == a->sz_a - 1)
		{
			ft_rra(a, 1);
			ft_sa(a, 1);
			ft_ra(a, 1);
			ft_ra(a, 1);
			inf->min = inf->min2;
			inf->last_min = inf->last_min2;
		}
		else
			return (1);
	}
	return (0);
}

static void	ft_put_nb_a_first(t_a *a, t_small *inf)
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
				return ;
			}
		}
		while (++i < a->sz_a - inf->pos - 1)
			ft_rra(a, 1);
	}
}

static void	ft_put_nb_a(t_a *a, int *min)
{
	int		i;
	int		pos;

	pos = ft_stk_get_pos(a->stk_a, *min);
	i = 0;
	while (++i <= pos)
		ft_pb(a, 1);
	ft_ra(a, 1);
}

static void	ft_put_nb_b(t_a *a, int *min)
{
	int		pos;
	int		i;

	pos = ft_stk_get_pos(a->stk_b, *min);
	i = -1;
	if (pos < ((a->sz_b >> 1) + (a->sz_b & 1)))
		while (++i < pos)
			ft_rb(a, 1);
	else
		while (++i < a->sz_b - pos)
			ft_rrb(a, 1);
	ft_pa(a, 1);
	ft_ra(a, 1);
}

void		ft_resolve_small(t_a *a)
{
	t_small		inf;

	inf.inf = NOTHING_SMALL;
	inf.last_min = (t_ll)INT_MIN - 1;
	inf.min = (t_ll)INT_MAX + 1;
	ft_get_min(a, &inf.min, &inf.last_min, &inf.inf);
	ft_put_nb_a_first(a, &inf);
	inf.last_min = inf.min;
	while (ft_is_sort(a, 0) == 0)
	{
		ft_get_min(a, &inf.min, &inf.last_min, &inf.inf);
		if (inf.inf & MIN_A)
			ft_put_nb_a(a, (int*)&inf.min);
		else
			ft_put_nb_b(a, (int*)&inf.min);
		inf.last_min = inf.min;
	}
}

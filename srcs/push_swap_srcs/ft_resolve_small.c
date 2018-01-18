/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:50:22 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 18:18:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_small.c                                       |
**   |     ft_get_min_stk(18 lines)                             |
**   |     ft_get_min(5 lines)                                  |
**   |     ft_put_nb_a_first(64 lines)                          |
**   |         MEUUUU too many lines                            |
**   |     ft_put_nb_a(12 lines)                                |
**   |     ft_put_nb_b(14 lines)                                |
**   |     ft_resolve_small(26 lines)                           |
**   |         MEUUUU too many lines                            |
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

static void	ft_put_nb_a_first(t_a *a, int *min, int *last_min, t_inf_small *inf)
{
	int		i;
	int		pos;
	int		pos2;
	t_ll	min2;
	t_ll	last_min2;

	pos = ft_stk_get_pos(a->stk_a, *min);
	min2 = *min;
	last_min2 = min2;
	i = -1;
	if (pos < (a->sz_a >> 1))
	{
		ft_get_min(a, &min2, &last_min2, inf);
		if (*inf & MIN_A)
		{
			pos2 = ft_stk_get_pos(a->stk_a, min2);
			if (pos2 + 1 == pos)
			{
				while (++i < pos2)
					ft_ra(a, 1);
				ft_sa(a, 1);
				ft_ra(a, 1);
				ft_ra(a, 1);
				*min = min2;
				*last_min = last_min2;
				return ;
			}
			else if (pos == 0 && pos2 == a->sz_a - 1)
			{
				ft_rra(a, 1);
				ft_sa(a, 1);
				ft_ra(a, 1);
				ft_ra(a, 1);
				*min = min2;
				*last_min = last_min2;
				return ;
			}
		}
		while (++i <= pos)
			ft_ra(a, 1);
	}
	else if (pos < a->sz_a - 1)
	{
		ft_get_min(a, &min2, &last_min2, inf);
		if (*inf & MIN_A)
		{
			pos2 = ft_stk_get_pos(a->stk_a, min2);
			if (pos2 + 1 == pos)
			{
				while (++i <= pos2)
					ft_pb(a, 1);
				ft_ra(a, 1);
				ft_pa(a, 1);
				ft_ra(a, 1);
				*min = min2;
				*last_min = last_min2;
				return ;
			}
		}
		while (++i < a->sz_a - pos - 1)
			ft_rra(a, 1);
	}
}

static void	ft_put_nb_a(t_a *a, int *min)
{
	int		i;
	int		pos;

//	ft_printf("PUT_A >>>>>>>>\n");//dd
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

//	ft_printf("PUT_B >>>>>>>>\n");//dd
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
	t_ll		min;
	t_ll		last_min;
	t_inf_small	inf;

	inf = NOTHING_SMALL;
//	ft_print(a);//dd
	last_min = (t_ll)INT_MIN - 1;
	min = (t_ll)INT_MAX + 1;
	/////
	ft_get_min(a, &min, &last_min, &inf);
//	ft_printf("(min %d) (a %d) (b %d)\n", min, (inf & MIN_A), (inf & MIN_B));//dd
	ft_put_nb_a_first(a, (int*)&min, (int*)&last_min, &inf);
	last_min = min;
	/////
	while (ft_is_sort(a, 0) == 0)
	{
//		ft_print(a);//dd
		ft_get_min(a, &min, &last_min, &inf);
//		ft_printf("(min %d) (a %d) (b %d)\n", min, (inf & MIN_A), (inf & MIN_B));//dd
		if (inf & MIN_A)
			ft_put_nb_a(a, (int*)&min);
		else
			ft_put_nb_b(a, (int*)&min);
		last_min = min;
	}
//	ft_print(a);//dd
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:21:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 10:54:25 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_swap.c                                        |
**   |     ft_sort_int(62 lines)                                |
**   |         MEUUUU too many lines                            |
**   |     ft_move_start(18 lines)                              |
**   |     ft_move_end(8 lines)                                 |
**   |     ft_sort_bloc(53 lines)                               |
**   |         MEUUUU too many lines                            |
**   |     ft_recurs(21 lines)                                  |
**   |     ft_resolve_swap(18 lines)                            |
**   |     ft_print_a(3 lines)                                  |
**   |     ft_print_b(3 lines)                                  |
**   |     ft_print(2 lines)                                    |
**   | MEUUUU too many functions                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |
**     |||   |||
*/

#include <push_swap.h>

static void	ft_sort_int(t_a *a, int sz_sort, t_inf inf)
{
	int		max;

	if (inf & DST_A)
	{
		if (a->stk_a->nb > a->stk_a->next->nb)
			ft_sa(a, 1);
		if (sz_sort == 3)
		{
			if (a->stk_a->next->nb > a->stk_a->next->next->nb)
			{
				ft_pb(a, 1);
				if (a->stk_a->nb > a->stk_a->next->nb)
					ft_sa(a, 1);
				ft_pa(a, 1);
				if (a->stk_a->nb > a->stk_a->next->nb)
					ft_sa(a, 1);
			}
		}
	}
	else
	{
		if (sz_sort == 2)
		{
			if (a->stk_a->nb > a->stk_a->next->nb)
				ft_sa(a, 1);
			ft_pb(a, 1);
			ft_pb(a, 1);
		}
		else
		{
			max = ft_max(a->stk_a->nb, ft_max(a->stk_a->next->nb, a->stk_a->next->next->nb));
			if (max == a->stk_a->next->next->nb)
			{
				if (a->stk_a->nb > a->stk_a->next->nb)
					ft_sa(a, 1);
				ft_pb(a, 1);
				ft_pb(a, 1);
				ft_pb(a, 1);
			}
			else if (max == a->stk_a->next->nb)
			{
				ft_pb(a, 1);
				ft_sa(a, 1);
				ft_pb(a, 1);
				if (a->stk_b->nb < a->stk_b->next->nb)
					ft_sb(a, 1);
				ft_pb(a, 1);
			}
			else
			{
				ft_sa(a, 1);
				ft_pb(a, 1);
				if (a->stk_a->nb > a->stk_a->next->nb)
					ft_sa(a, 1);
				ft_pb(a, 1);
				if (a->stk_b->nb < a->stk_b->next->nb)
					ft_sb(a, 1);
				ft_pb(a, 1);
			}
		}
	}
}

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

static void	ft_sort_bloc(t_a *a, int sz_sort, t_inf inf)
{
	int		sz1;
	int		pos_sz1;
	int		sz2;

	if (inf & DST_A)
	{
		pos_sz1 = 0;
		sz1 = sz_sort >> 1;
		sz2 = ((sz_sort & 1) == 0) ? sz1 : sz1++;
		ft_move_start(a, sz1, &pos_sz1, inf);
		while (sz2 > 0)
		{
			if (((a->stk_b->nb < a->stk_a->nb) &&
						((pos_sz1 == 0) || (a->stk_b->nb > ft_stk_getlast(a->stk_a)->nb)))
					|| (pos_sz1 == sz1))
			{
				ft_pa(a, 1);
				--sz2;
				++sz1;
			}
			else
			{
				ft_rra(a, 1);
				--pos_sz1;
			}
		}
		ft_move_end(a, &pos_sz1, inf);
	}
	else
	{
		pos_sz1 = 0;
		sz1 = sz_sort >> 1;
		sz2 = ((sz_sort & 1) == 0) ? sz1 : sz1++;
		ft_move_start(a, sz2, &pos_sz1, inf);
		while (sz1 > 0)
		{
			if (((a->stk_a->nb > a->stk_b->nb) &&
						((pos_sz1 == 0) || (a->stk_a->nb < ft_stk_getlast(a->stk_b)->nb)))
					|| (pos_sz1 == sz2))
			{
				ft_pb(a, 1);
				++sz2;
				--sz1;
			}
			else
			{
				ft_rrb(a, 1);
				--pos_sz1;
			}
		}
		ft_move_end(a, &pos_sz1, inf);
	}
}

static void	ft_recurs(t_a *a, int sz_sort, t_inf inf)
{
	int		sz1;
	int		sz2;

	if (sz_sort <= 3)
	{
//		ft_printf("{red}start sort_int (nb_int %d) (dst %c)\n", sz_sort, ((inf & DST_A) ? 'A' : 'B'));//dd
//		ft_printf("{%s}>>> %c <<<{eoc}\n", ((inf & DST_A) ? "green" : "red"), ((inf & DST_A) ? 'A' : 'B'));
		ft_sort_int(a, sz_sort, inf);
//		ft_printf("end sort_int %d{eoc}\n", sz_sort);//dd
		return ;
	}
	sz1 = sz_sort >> 1;
	sz2 = ((sz_sort & 1) == 0) ? sz1 : sz1 + 1;
	ft_recurs(a, sz1, SRC_A | DST_B);
	ft_recurs(a, sz2, SRC_A | DST_A);
//	ft_printf("{green}start sort_bloc (nb_int %d) (dst %c)\n", sz_sort, ((inf & DST_A) ? 'A' : 'B'));//dd
	ft_sort_bloc(a, sz_sort, inf);
//	ft_printf("end sort_bloc %d{eoc}\n", sz_sort);//dd
}

void		ft_resolve_swap(t_a *a)
{
	int		end;
	t_stk	*stk;

//	ft_print(a);//dd
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
	if (a->sz_list < 30)
		ft_resolve_small(a);
	else
		ft_recurs(a, a->sz_list, SRC_A | DST_A);
//	ft_print(a);//dd
}


void		ft_print_a(t_a *a)
{
		ft_printf("stack a:\n<<<\n{yellow}");
		ft_stk_print(a->stk_a);
		ft_printf("{eoc}>>>\n");
}

void		ft_print_b(t_a *a)
{
		ft_printf("stack b:\n<<<\n{yellow}");
		ft_stk_print(a->stk_b);
		ft_printf("{eoc}>>>\n");
}

void		ft_print(t_a *a)
{
	ft_print_a(a);
	ft_print_b(a);
}

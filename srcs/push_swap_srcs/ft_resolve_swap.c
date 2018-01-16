/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:21:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/16 20:08:55 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_swap.c                                        |
**   |     ft_sort_int(12 lines)                                |
**   |     ft_move_start(6 lines)                               |
**   |     ft_move_end(5 lines)                                 |
**   |     ft_sort_bloc(36 lines)                               |
**   |         MEUUUU too many lines                            |
**   |     ft_recurs(27 lines)                                  |
**   |         MEUUUU too many lines                            |
**   |     ft_resolve_swap(3 lines)                             |
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

static void	ft_sort_int(t_a *a, int sz_sort)
{
	if (a->stk_a->nb > a->stk_a->next->nb)
		ft_sa(a, 1);
	if (sz_sort == 3)
	{
		if (a->stk_a->next->nb > a->stk_a->next->next->nb)
		{
			ft_pb(a, 1);
			ft_sort_int(a, 2);
			ft_pa(a, 1);
			ft_sort_int(a, 2);
		}
	}
}

static void	ft_move_start(t_a *a, int sz1, int *pos_sz1)
{
	while (sz1 > 0 && a->stk_b->nb > a->stk_a->nb)
	{
		ft_ra(a, 1);
		--sz1;
		(*pos_sz1)++;
	}
}

static void	ft_move_end(t_a *a, int *pos_sz1)
{
	while (*pos_sz1 > 0)
	{
		ft_rra(a, 1);
		(*pos_sz1)--;
	}
}

static void	ft_sort_bloc(t_a *a, int sz_sort)
{
	int		sz1;
	int		pos_sz1;
	int		sz2;

	pos_sz1 = 0;
	sz1 = sz_sort >> 1;
	if ((sz_sort & 1) == 0)
		sz2 = sz1;
	else
		sz2 = sz1++;
	ft_move_start(a, sz1, &pos_sz1);
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
		else// if (pos_sz1 > 0)
		{
			ft_rra(a, 1);
			--pos_sz1;
		}
//		else
//		{
//			ft_printf("{eoc}{RED}c'est Ugo{eoc}\n");
//			ft_printf("\t(sz1 %d) (sz2 %d) (stka %d) (stkb %d) (pos_sz1 %d)\n", sz1, sz2, a->stk_a->nb, a->stk_b->nb, pos_sz1);
//			break;
//		}

	}
	ft_move_end(a, &pos_sz1);
}

static void	ft_recurs(t_a *a, int sz_sort)
{
	int		i;
	int		sz1;
	int		sz2;

	if (sz_sort <= 3)
	{
//		ft_printf("{red}start sort_int %d\n", sz_sort);//dd
		ft_sort_int(a, sz_sort);
//		ft_printf("end sort_int %d{eoc}\n", sz_sort);//dd
		return ;
	}
	sz1 = sz_sort >> 1;
	if ((sz_sort & 1) == 0)
		sz2 = sz1;
	else
		sz2 = sz1 + 1;
	ft_recurs(a, sz1);
//	ft_printf("{magenta}start push b before recurs 2\n");//dd
	i = -1;
	while (++i < sz1)
		ft_pb(a, 1);
//	ft_printf("end push b before recurs 2{eoc}\n");//dd
	ft_recurs(a, sz2);
//	ft_printf("{green}start sort_bloc %d\n", sz_sort);//dd
	ft_sort_bloc(a, sz_sort);
//	ft_printf("end sort_bloc %d{eoc}\n", sz_sort);//dd
}

void		ft_resolve_swap(t_a *a)
{
//	ft_print(a);//dd
	ft_recurs(a, a->sz_list);
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

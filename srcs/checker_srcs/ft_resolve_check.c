/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:02:05 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 14:47:23 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_resolve_check.c                                       |
**   |     ft_forest(24 lines)                                  |
**   |     ft_resolve_check(12 lines)                           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

static void	ft_forest(t_a *a, char *arg)
{
	if (ft_strcmp(arg, SA) == 0)
		ft_sa(a, 0);
	else if (ft_strcmp(arg, SB) == 0)
		ft_sb(a, 0);
	else if (ft_strcmp(arg, SS) == 0)
		ft_ss(a, 0);
	else if (ft_strcmp(arg, PA) == 0)
		ft_pa(a, 0);
	else if (ft_strcmp(arg, PB) == 0)
		ft_pb(a, 0);
	else if (ft_strcmp(arg, RA) == 0)
		ft_ra(a, 0);
	else if (ft_strcmp(arg, RB) == 0)
		ft_rb(a, 0);
	else if (ft_strcmp(arg, RR) == 0)
		ft_rr(a, 0);
	else if (ft_strcmp(arg, RRA) == 0)
		ft_rra(a, 0);
	else if (ft_strcmp(arg, RRB) == 0)
		ft_rrb(a, 0);
	else if (ft_strcmp(arg, RRR) == 0)
		ft_rrr(a, 0);
	else if (ft_fruit(1, arg))
		ft_error();
}

void		ft_resolve_check(t_a *a)
{
	char	*arg;
	int		ret;

	ft_print(a);
	while ((ret = get_next_line(STDIN_FILENO, &arg)) == GNL_LINE_READ)
	{
		ft_forest(a, arg);
		free(arg);
		ft_print(a);
	}
	if (ret == GNL_ERROR)
		ft_error();
}

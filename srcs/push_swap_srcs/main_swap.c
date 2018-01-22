/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:14:58 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 22:54:14 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main_swap.c                                              |
**   |     main(11 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

int			main(int ac, char **av)
{
	t_a		a;

	if (ac > 2)
	{
		a.print = 0;
		if (ac >= 3 && ft_strcmp("-v", av[1]) == 0)
		{
			a.print = 1;
			ft_create_stack(&a, ac - 2, av + 2);
		}
		else
			ft_create_stack(&a, ac - 1, av + 1);
		ft_resolve_swap(&a);
		ft_close_swap(&a);
	}
	else
		ft_error();
	return (0);
}

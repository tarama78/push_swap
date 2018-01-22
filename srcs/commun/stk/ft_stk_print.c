/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:28:58 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 22:54:15 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_stk_print.c                                           |
**   |     ft_stk_print(5 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

void		ft_stk_print(t_stk *stk)
{
	if (stk)
	{
		ft_printf("%d\n", stk->nb);
		ft_stk_print(stk->next);
	}
}

void		ft_print(t_a *a)
{
	if (a->print)
	{
		ft_printf("{green}stack A:\n<<<\n");
		ft_stk_print(a->stk_a);
		ft_printf(">>>\n{magenta}stack B:\n<<<\n");
		ft_stk_print(a->stk_b);
		ft_printf(">>>\n{eoc}");
	}
}

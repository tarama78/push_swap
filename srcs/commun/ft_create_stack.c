/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:37:47 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/17 15:22:18 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_create_stack.c                                        |
**   |     ft_check_nb(13 lines)                                |
**   |     ft_create_stack(11 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <push_swap.h>

static void	ft_doublon(t_a *a, int nb)
{
	t_stk	*stk;

	stk = a->stk_a;
	while (stk)
	{
		if (stk->nb == nb)
		{
			ft_stk_del(&a->stk_a);
			ft_error();
		}
		stk = stk->next;
	}
}

static int	ft_check_nb(char *s, int *nb)
{
	int		i;
	t_ll	nb_ll;

	i = (s[0] == '-') ? 0 : -1;
	while (ft_isdigit(s[++i]) && s[i])
		;
	if (s[i] != '\0')
		return (ERROR);
	nb_ll = ft_atol(s);
	if (nb_ll > INT_MAX || nb_ll < INT_MIN)
		return (ERROR);
	*nb = (int)nb_ll;
	return (SUCCESS);
}

void		ft_create_stack(t_a *a, int sz, char **arg)
{
	int		nb;
	int		i;

	i = sz;
	a->sz_a = 0;
	a->sz_b = 0;
	a->stk_b = NULL;
	while (--i >= 0)
	{
		if (ft_check_nb(arg[i], &nb) == ERROR)
		{
			if (i < sz - 1)
				ft_stk_del(&a->stk_a);
			ft_error();
		}
		ft_doublon(a, nb);
		ft_stk_add(&a->stk_a, nb);
		a->sz_a++;
	}
	a->sz_list = a->sz_a;
}

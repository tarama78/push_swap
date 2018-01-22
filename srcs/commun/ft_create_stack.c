/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:37:47 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/22 11:27:22 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_create_stack.c                                        |
**   |     ft_doublon(12 lines)                                 |
**   |     ft_check_nb(13 lines)                                |
**   |     ft_create_stack(20 lines)                            |
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
	a->stk_a = NULL;
	a->stk_b = NULL;
	while (--i >= 0)
	{
		if (ft_strlen(arg[i]) >= 11)
			ft_error();
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

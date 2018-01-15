/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:37:47 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 17:39:59 by tnicolas         ###   ########.fr       */
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
	while (--i >= 0)
	{
		if (ft_check_nb(arg[i], &nb) == ERROR)
			ft_error();
		ft_stk_add(&a->stk_a, nb);
	}
	a->stk_b = NULL;
}

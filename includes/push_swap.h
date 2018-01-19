/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:27:40 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/18 22:54:14 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <push_swap_struct.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** commun
*/

void		ft_create_stack(t_a *a, int sz, char **arg);
void		ft_error();

t_stk		*ft_stk_add(t_stk **first, int nb);
void		ft_stk_del(t_stk **stk);
t_stk		*ft_stk_get(t_stk *first, int n);
int			ft_stk_get_pos(t_stk *first, int nb);
t_stk		*ft_stk_getlast(t_stk *first);
void		ft_stk_print(t_stk *stk);

int			ft_sa(t_a *a, int print);
int			ft_sb(t_a *a, int print);
int			ft_ss(t_a *a, int print);
int			ft_pa(t_a *a, int print);
int			ft_pb(t_a *a, int print);
int			ft_ra(t_a *a, int print);
int			ft_rb(t_a *a, int print);
int			ft_rr(t_a *a, int print);
int			ft_rra(t_a *a, int print);
int			ft_rrb(t_a *a, int print);
int			ft_rrr(t_a *a, int print);

/*
** push_swap
*/

void		ft_sort_bloc(t_a *a, int sz_sort, t_inf inf);
void		ft_resolve_swap(t_a *a);
void		ft_put_nb_a_first(t_a *a, t_small *inf);
void		ft_get_min(t_a *a, t_ll *min, t_ll *last_min, t_inf_small *inf);
void		ft_resolve_small(t_a *a);
void		ft_close_swap(t_a *a);

/*
** checker
*/

void		ft_close_check(t_a *a);
void		ft_resolve_check(t_a *a);
int			ft_is_sort(t_a *a, int print);

#endif

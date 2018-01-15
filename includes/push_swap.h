/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:27:40 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 18:17:56 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <push_swap_struct.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void		ft_create_stack(t_a *a, int sz, char **arg);
void		ft_error();
void		ft_close_check(t_a *a);
void		ft_resolve(t_a *a);
void		ft_verif_end(t_a *a);

t_stk		*ft_stk_add(t_stk **first, int nb);
void		ft_stk_del(t_stk **stk);
void		ft_stk_print(t_stk *stk);

void		ft_sa(t_a *a);
void		ft_sb(t_a *a);
void		ft_ss(t_a *a);
void		ft_pa(t_a *a);
void		ft_pb(t_a *a);
void		ft_ra(t_a *a);
void		ft_rb(t_a *a);
void		ft_rr(t_a *a);
void		ft_rra(t_a *a);
void		ft_rrb(t_a *a);
void		ft_rrr(t_a *a);

#endif

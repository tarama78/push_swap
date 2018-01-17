/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:32:07 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/17 11:43:40 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

# define ERROR_MSG "Error\n"
# define ERROR -1
# define SUCCESS 0

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef unsigned int		t_ui;
typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef enum		e_inf
{
	NOTHING = 0x0,
	SRC_A = 0x1,
	SRC_B = 0x2,
	DST_A = 0x4,
	DST_B = 0x8
}					t_inf;

typedef struct		s_stk
{
	int				nb;
	struct s_stk	*next;
}					t_stk;

typedef struct		s_a
{
	t_stk			*stk_a;
	t_stk			*stk_b;
	int				sz_a;
	int				sz_b;
	int				sz_list;
}					t_a;

#endif

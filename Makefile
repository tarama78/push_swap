# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:45:36 by tnicolas          #+#    #+#              #
#    Updated: 2018/01/22 11:24:57 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                      __      ___                             #
#                                      \ \    / (_)                            #
#                 ___  ___ _ __ __ _  __\ \  / / _ _ __ ___                    #
#                / __|/ _ \ '__/ _` |/ _ \ \/ / | | '_ ` _ \                   #
#                \__ \  __/ | | (_| |  __/\  /  | | | | | | |                  #
#                |___/\___|_|  \__, |\___| \/   |_|_| |_| |_|                  #
#                               __/ |                                          #
#                              |___/                                           #
#                                                                              #
# **************************************************************************** #

NAME_CHECK = checker
NAME_SWAP = push_swap

ARG = 5 2 3 4 0 1

FILES_CHECK = main_check.c \
			  ft_close_check.c \
			  ft_resolve_check.c

FILES_SWAP = main_swap.c \
			 ft_sort_bloc.c \
			 ft_resolve_swap.c \
			 ft_resolve_small_2.c \
			 ft_resolve_small.c \
			 ft_close_swap.c

FILES = ft_create_stack.c \
		ft_error.c \
		ft_is_sort.c \
		stk/ft_stk_add.c \
		stk/ft_stk_del.c \
		stk/ft_stk_get.c \
		stk/ft_stk_getlast.c \
		stk/ft_stk_print.c \
		stk/ft_ss.c \
		stk/ft_pp.c \
		stk/ft_rr.c \
		stk/ft_rrr.c

HFILES = includes/push_swap.h \
		 includes/push_swap_struct.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/ \
		  $(LIBFT_DIR)includes/ \
		  $(LIBFT_DIR)includes/ft_printf/
SRCS_DIR = srcs/
OBJ_DIR = objs/

LIBFT_DIR = libft/
LIBFT_LIB = -L $(LIBFT_DIR) -lft

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR)commun/, $(FILES))
OBJ := $(addprefix $(OBJ_DIR)commun/, $(FILES:.c=.o))
SRCS_CHECK := $(addprefix $(SRCS_DIR)checker_srcs/, $(FILES_CHECK))
OBJ_CHECK := $(addprefix $(OBJ_DIR)checker_srcs/, $(FILES_CHECK:.c=.o))
SRCS_SWAP := $(addprefix $(SRCS_DIR)push_swap_srcs/, $(FILES_SWAP))
OBJ_SWAP := $(addprefix $(OBJ_DIR)push_swap_srcs/, $(FILES_SWAP:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"

START_CHECK = @printf $(GREEN)"CHECKER\n--------------------\n"$(NORMAL)
END_CHECK = @printf $(GREEN)"--------------------\n"$(NORMAL)

START_SWAP = @printf $(GREEN)"PUSH_SWAP\n--------------------\n"$(NORMAL)
END_SWAP = @printf $(GREEN)"--------------------\n"$(NORMAL)

all:
	@make -C $(LIBFT_DIR)
	$(START_CHECK)
	@make $(NAME_CHECK)
	$(END_CHECK)
	$(START_SWAP)
	@make $(NAME_SWAP)
	$(END_SWAP)

$(NAME_CHECK): $(LIBFT_DIR)libft.a $(OBJ_DIR) $(OBJ_CHECK) $(OBJ)
	@printf $(CYAN)"-> create program : $(NAME_CHECK)\n"$(NORMAL)
	@$(CC) -o $(NAME_CHECK) $(OBJ_CHECK) $(OBJ) $(CFLAGS) $(LIBFT_LIB)

$(NAME_SWAP): $(LIBFT_DIR)libft.a $(OBJ_DIR) $(OBJ_SWAP) $(OBJ)
	@printf $(CYAN)"-> create program : $(NAME_SWAP)\n"$(NORMAL)
	@$(CC) -o $(NAME_SWAP) $(OBJ_SWAP) $(OBJ) $(CFLAGS) $(LIBFT_LIB)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HFILES) $(OBJ_DIR) $(LIBFT_DIR)libft.a
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(dir $(OBJ_CHECK))
	@mkdir -p $(dir $(OBJ_SWAP))
	@mkdir -p $(dir $(OBJ))

$(LIBFT_DIR)libft.a:
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(START_SWAP)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJ_DIR)
	$(END_SWAP)

fclean: clean
	@make -C $(LIBFT_DIR) cleanlib
	$(START_SWAP)
	@printf $(RED)"-x remove $(NAME_SWAP) $(NAME_CHECK)\n"$(NORMAL)
	@rm -f $(NAME_SWAP) $(NAME_CHECK)
	$(END_SWAP)

re: fclean
	@make

exec:
	@clear
	@make
	@printf $(MAGENTA)"EXEC\n--------------------\n"$(NORMAL)
	@printf $(YELLOW)"stack:\n{\n"$(NORMAL)
	@echo $(ARG) | tr " " "\n" | sed "s/^/    /g"
	@printf $(YELLOW)"}\n\ninstructions:\n{\n"$(NORMAL)
	@./$(NAME_SWAP) $(ARG) | sed "s/^/    /g"
	@printf $(YELLOW)"}\n\nnb d'instruction:\n{\n"$(GREEN)
	@./$(NAME_SWAP) $(ARG) 2> .error | wc -l | sed "s/ //g" | sed "s/^/    /g"
	@printf $(YELLOW)"}\n\nresult:\n{\n"$(NORMAL)
	@./$(NAME_SWAP) $(ARG) 2> .error | ./$(NAME_CHECK) $(ARG) | sed "s/^/    /g"
	@printf $(YELLOW)"}\n"$(NORMAL)
	@printf $(MAGENTA)"--------------------\n"$(NORMAL)

exec_checker:
	@clear
	@make
	@printf $(MAGENTA)"EXEC CHECKER\n--------------------\n"$(NORMAL)
	./$(NAME_CHECK) $(ARG)
	@printf $(MAGENTA)"--------------------\n"$(NORMAL)

exec_push_swap:
	@clear
	@make
	@printf $(MAGENTA)"EXEC PUSH_SWAP\n--------------------\n"$(NORMAL)
	./$(NAME_SWAP) $(ARG) | wc -l
	./$(NAME_SWAP) $(ARG)
	@printf $(MAGENTA)"--------------------\n"$(NORMAL)

test:
	@./$(NAME_SWAP) $(ARG) | wc -l | sed "s/ //g" | tr "\n" "\t"
	@./$(NAME_SWAP) $(ARG) | ./$(NAME_CHECK) $(ARG) | sed "s/KO/KO >>> FAIL!!!/g"

open:
	@vim +Line `git config --get remote.origin.url | sed "s/..*/+SergeGit/"` $(HFILES) $(SRCS_CHECK) $(SRCS_SWAP) $(SRCS) Makefile

open_checker:
	@vim +Line `git config --get remote.origin.url | sed "s/..*/+SergeGit/"` $(HFILES) $(SRCS_CHECK) $(SRCS) Makefile

open_push_swap:
	@vim +Line `git config --get remote.origin.url | sed "s/..*/+SergeGit/"` $(HFILES) $(SRCS_SWAP) $(SRCS) Makefile

norm:
	@make -C $(LIBFT_DIR) norm
	@printf $(BLUE)"NORME FDF\n--------------------\n"$(NORMAL)
	@norminette $(SRCS_CHECK) $(SRCS_SWAP) $(HFILES)
	@printf $(BLUE)"--------------------\n"$(NORMAL)

.PHONY: all clean fclean re norm force

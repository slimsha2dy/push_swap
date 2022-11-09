# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 16:29:08 by hwichoi           #+#    #+#              #
#    Updated: 2022/11/09 15:53:05 by hwichoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= push_swap.c \
			  arr_utils.c \
			  arr.c \
			  rr.c \
			  rrr.c \
			  sp.c \
			  sort_rotate.c \
			  sort_rotate_utils.c \
			  sort_utils.c \
			  sort.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cc -o $(NAME) $(OBJS) -Llibft -lft -g3 -fsanitize=address

%.o: %.c
	cc $(FLAGS) -c $^ -I./ -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)


re: fclean all

.PHONY: all clean fclean re

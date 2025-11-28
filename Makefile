# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 11:14:50 by bhibbeln          #+#    #+#              #
#    Updated: 2025/11/28 22:43:51 by bhibbeln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./ft_printf.a
FT_PRINTF = ./ft_printf/ft_printf.a

SRC = 	ft_split.c \
		error.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_three.c \
		sort_chunk.c \
		stack_init.c \
		stack_utils.c \
		swap.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

MAKEFLAGS += -s

$(NAME): $(OBJS)
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)
	@echo "✅ push_swap compiled"

clean:
	@rm -f $(OBJS)
	@make -C ./ft_printf clean
	@echo "❌ Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -C ./ft_printf fclean
	@echo "❌ push_swap removed"

re: fclean all

.PHONY: all clean fclean re

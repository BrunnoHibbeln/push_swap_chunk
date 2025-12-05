# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhibbeln <bhibbeln@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 11:14:50 by bhibbeln          #+#    #+#              #
#    Updated: 2025/12/05 12:03:24 by bhibbeln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./ft_printf.a
FT_PRINTF = ./ft_printf/ft_printf.a

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
RESET=\033[0m

SRC = 	ft_split.c \
		error.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_three.c \
		sort_five.c \
		sort_chunk.c \
		sort_chunk_utils.c \
		stack_init.c \
		stack_utils.c \
		swap.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

MAKEFLAGS += -s

$(NAME): $(OBJS)
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)✅ push_swap compiled$(RESET)"

clean:
	@rm -f $(OBJS)
	@make -C ./ft_printf clean
	@echo "$(RED)❌ Object files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C ./ft_printf fclean
	@echo "$(RED)❌ push_swap deleted$(RESET)"

re: fclean all
	@echo "$(YELLOW)🟡 Everything recompiled$(RESET)"

.PHONY: all clean fclean re

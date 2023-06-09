# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:14:44 by minkyole          #+#    #+#              #
#    Updated: 2023/05/31 17:14:45 by minkyole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BNAME = checker
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
SRCS = list1.c list2.c command1.c command2.c main.c push_swap_util.c sort.c list_command1.c list_command2.c sort_two.c sort_three.c sort_util1.c sort_four.c sort_five.c quick_sort_div.c quick_sort_size.c sort_three_2.c sort_five_2.c quick_sort.c quick_sort_restore.c
BSRCS = checker_bonus.c list1_bonus.c list2_bonus.c command1_bonus.c command2_bonus.c checker_util_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

.PHONY : clean fclean re all bonus

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C $(LIBFT_DIR) fclean

fclean:
	$(MAKE) clean
	rm -f $(BNAME)
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: $(BNAME)

$(BNAME): $(BOBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

all: $(NAME) $(BNAME)
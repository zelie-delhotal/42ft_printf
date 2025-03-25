# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:50:51 by gdelhota          #+#    #+#              #
#    Updated: 2024/11/14 00:24:16 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

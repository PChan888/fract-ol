# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kai <kai@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 03:37:45 by kai               #+#    #+#              #
#    Updated: 2026/06/22 02:12:42 by kai              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = Libft/libft.a

MLX = minilibx-linux/libmlx.a

SRCS = 	main.c \
		parser.c \
		init.c \
		render.c \
		hsv_colour.c \
		events.c \
		zoom.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C Libft

$(MLX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C Libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re

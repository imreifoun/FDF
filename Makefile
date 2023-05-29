# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 11:35:45 by areifoun          #+#    #+#              #
#    Updated: 2023/03/29 22:04:44 by areifoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror

EXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	read_map.c \
	fill_map.c \
	draw.c \
	template.c \
	fill_outils.c
	
OBJ = $(SRC:.c=.o)

HEADERS = fdf.h

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(EXFLAGS) $^ -o $@

$(LIBFT):
	@make -C libft

%.o: %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	
fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	
re: fclean all
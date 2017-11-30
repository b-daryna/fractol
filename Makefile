# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2017/02/24 13:55:02 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

LIBFT = ./libft/libft.a

FTPRINTF = ./libft/ft_printf/libftprintf.a

SRC = 	main.c \
		create_fractal.c \
	  	draw.c \
		key_hook.c \
		mouse_hook.c \
	  	error.c \

FLAGS = -Wall -Wextra -Werror

OBJ     = $(SRC:.c=.o)

all     : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(FTPRINTF)
	    gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(FTPRINTF) \
			        -O3 -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $<

$(LIBFT)  :
	    make -C libft/

$(FTPRINTF)  :
	    make -C libft/ft_printf/

lclean  :
	    make -C libft/ clean
	    make -C libft/ft_printf/ clean

clean   : lclean
	    rm -f $(OBJ)

fclean  : clean
	    rm -f $(NAME)
		rm -f libft/libft.a
		rm -f libft/ft_printf/libftprintf.a

re: fclean all

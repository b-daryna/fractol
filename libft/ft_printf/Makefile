# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2017/04/11 17:42:45 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =   ft_atoi.c \
        ft_printf.c \
        ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_intsize.c \
		ft_strchr.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_strdel.c \
		int.c \
		double.c \
		char.c \
		wchar.c \
		helpers.c \
		put_nbr.c \
		length.c \
		spec_helper.c \
		specifier.c \
		str_helpers.c\
		prefix.c \

OBJ = $(SRC:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

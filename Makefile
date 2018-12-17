# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averemiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/26 13:54:07 by averemiy          #+#    #+#              #
#    Updated: 2018/08/26 14:57:22 by averemiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

PRINTF = ./ft_printf/libftprintf.a

SRC = ./create_hash_md5.c ./create_hash_sha256.c ./create_hash_sha512.c ./ft_ssl_main.c \
	  ./helper_function_md5.c ./helper_function_sha256.c ./helper_function_sha512.c \
	  ./helper_parser.c ./md5_hash.c ./parser.c ./round_md5.c ./sha256_hash.c \
	  ./sha512_hash.c ./helper_parser2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./ft_printf/
	gcc $(FLAGS) $(SRC) $(PRINTF) -o $(NAME)

clean :
	make -C ./ft_printf/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./ft_printf/ fclean
	rm -rf $(NAME)
	rm -rf libftprintf.a

re : fclean all


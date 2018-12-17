# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averemiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 13:30:33 by averemiy          #+#    #+#              #
#    Updated: 2018/04/05 15:14:00 by averemiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ./print.h ./libft.h

GFLAG = -Wall -Wextra

SRC = ./ft_printf.c ./ft_putchar.c ./ft_reverse.c ./ft_putstr.c \
	./ft_strcmp.c ./ft_strcat.c ./ft_strcpy.c ./ft_strdup.c \
	./ft_strjoin.c ./ft_strnew.c ./ft_strsub.c ./ft_toupper.c \
	./check_valid.c ./findsymb.c ./for_print_spec.c ./freesh.c \
	./find_flags.c ./find_rigth_solve.c ./ft_itoal.c ./ft_uitoa.c \
	./int_printer.c ./octat_to_d.c ./parser.c ./print_null.c \
	./printall.c ./printer_for_memory.c ./printer_to_wch_s.c \
	./str_printer.c ./uint_printer.c ./wchar_printer.c ./make_h.c \
	./make_int_str.c ./make_o.c ./printall_p.c ./ft_bzero.c \
	./ft_strlen.c ./help_hex.c

SRCC = ./ft_printf.o ./ft_putchar.o ./ft_reverse.o ./ft_putstr.o \
	./ft_strcmp.o ./ft_strcat.o ./ft_strcpy.o ./ft_strdup.o \
	./ft_strjoin.o ./ft_strnew.o ./ft_strsub.o ./ft_toupper.o \
	./check_valid.o ./findsymb.o ./for_print_spec.o ./freesh.o \
	./find_flags.o ./find_rigth_solve.o ./ft_itoal.o ./ft_uitoa.o \
	./int_printer.o ./octat_to_d.o ./parser.o ./print_null.o \
	./printall.o ./printer_for_memory.o ./printer_to_wch_s.o \
	./str_printer.o ./uint_printer.o ./wchar_printer.o ./make_h.o \
	./make_int_str.o ./make_o.o ./printall_p.o ./ft_bzero.o \
	./ft_strlen.o ./help_hex.o

all: $(NAME)

$(NAME):
	gcc $(GFLAG) $< -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(SRCC)

clean :
	rm -f $(SRCC)

fclean : clean
	rm -f $(NAME)

re : fclean all

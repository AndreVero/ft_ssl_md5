/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:38:22 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/26 15:58:11 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_spe
{
	int			plus;
	int			minus;
	int			size;
	int			size_spec;
	int			zero;
	int			hash;
	int			space;
	char		*size_mdf;
	char		symb;
	int			for_plus;
	int			pointer;
	int			output;
}				t_spe;

char			*help_hex(unsigned long long int d);
int				find_size_spec(t_spe **t, char *s, int i);
char			*find_size_modifire(char *s, int i);
int				how_many_char(wchar_t c);
int				str_w_length(wchar_t *str);
void			freesher_for_2(char *str1, char *str2);
int				ft_printf(char const *arg, ...);
t_spe			*make_elem(char *str, int i);
void			tester(t_spe *t);
int				find_flags(char *s, t_spe **t);
int				int_printer(t_spe **t, long long int count);
int				str_printer(t_spe **t, char *str);
int				printall(char *str, t_spe **t, int size_of_result);
int				printall_p(char *str, t_spe **t, int size_of_result);
int				find_rigth_solve(char *str, va_list ap);
void			find_right_for_void(t_spe **t, void *p);
char			*ft_itoal(long long int n);
char			*m(char *our, int size);
int				uint_printer(t_spe **t, unsigned long long count);
char			*ft_utoal(unsigned long long n);
int				make_o(t_spe **t, unsigned long long int d);
int				dec_to_oct(t_spe **t, unsigned long long int d);
int				decimal_to_hex(t_spe **t, unsigned long long int d);
int				make_h(t_spe **t, unsigned long long int d);
int				printer_for_wchar(wchar_t c);
int				printer_to_wch_s(t_spe **t, wchar_t *str);
int				print_for_memory(t_spe **t, void **tmp);
void			print_null(t_spe **t);
char			findsymb(unsigned long long del);
int				print_right_wch(t_spe **t, wchar_t d);
char			*create_null();
char			*make_int_minus(t_spe **t, long long int c);
char			*make_int_plus(t_spe **t, long long int c);
char			*make_int_space(t_spe **t, long long int c);
int				make_hex_write(t_spe **t, unsigned long long int c);
int				check_valid(char *str);
t_spe			*not_valid(char *after_pars);
int				first_word(t_spe **t, int size, wchar_t *str, int spe);
int				second_word(t_spe **t, int size, wchar_t *str, int spe);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rigth_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:13:47 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 14:43:18 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdarg.h>

static int			find_symb(t_spe **t, char c)
{
	if (c == 'd' || c == 'i' || c == 'D'
			|| (!ft_strcmp((*t)->size_mdf, "j") && c == 'd')
			|| (!ft_strcmp((*t)->size_mdf, "z") && c == 'd'))
		return (1);
	return (0);
}

static int			unsigned_flags(t_spe *t)
{
	if ((t->symb == 'u') || (t->symb == 'U'))
		return (1);
	return (0);
}

static int			find_big_str_flag(t_spe *t)
{
	if ((!ft_strcmp(t->size_mdf, "l") && t->symb == 's')
			|| t->symb == 'S')
		return (1);
	return (0);
}

int					put_for_right_flag(va_list ap, t_spe **t)
{
	if (find_symb(t, (*t)->symb))
		return ((int_printer(t, va_arg(ap, long long))));
	else if (unsigned_flags(*t))
		return (uint_printer(t, va_arg(ap, unsigned long long)));
	else if (find_big_str_flag(*t))
		return (printer_to_wch_s(t, va_arg(ap, wchar_t *)));
	else if ((*t)->symb == 's')
		return (str_printer(t, va_arg(ap, char *)));
	else if ((*t)->symb == 'p')
		return (print_for_memory(t, va_arg(ap, void **)));
	else if ((*t)->symb == 'o')
		return (make_o(t, va_arg(ap, unsigned long long int)));
	else if ((*t)->symb == 'O')
		return (dec_to_oct(t, va_arg(ap, unsigned long long int)));
	else if ((*t)->symb == 'x' || (*t)->symb == 'X')
		return (make_h(t, va_arg(ap, unsigned long long int)));
	else if ((*t)->symb == 'c' || (*t)->symb == 'C')
		return (print_right_wch(t, va_arg(ap, wchar_t)));
	else if ((*t)->symb == '%')
	{
		if ((*t)->size_spec == 1)
			(*t)->size_spec += 1;
		return (print_right_wch(t, '%'));
	}
	return (print_right_wch(t, (wchar_t)0) - 1);
}

int					find_rigth_solve(char *str, va_list ap)
{
	int				i;
	t_spe			*t;
	int				k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			t = make_elem(str, i);
			k += put_for_right_flag(ap, &t);
			i += (t->for_plus + 1);
			free(t->size_mdf);
			t->symb = 0;
			t->size_mdf = NULL;
			free(t);
		}
		else
		{
			ft_putchar(str[i++]);
			k++;
		}
	}
	return (k);
}

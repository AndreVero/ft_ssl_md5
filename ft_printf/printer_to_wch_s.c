/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_to_wch_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:29:34 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:26:32 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int				str_w_length(wchar_t *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7f)
			i++;
		else if (*str <= 0x7ff)
			i += 2;
		else if (*str <= 0xffff)
			i += 3;
		else
			i += 4;
		str++;
	}
	return (i);
}

static int		print_all_word_spe(t_spe **t, wchar_t *str)
{
	int			i;
	int			j;
	int			res;
	int			minus;

	res = 0;
	minus = 0;
	j = str_w_length(str);
	i = (*t)->size_spec;
	while (j < i)
	{
		ft_putchar('0');
		j++;
		res++;
	}
	while (*str && i > 0 && (i - minus) > 0)
	{
		minus = printer_for_wchar(*str);
		str++;
		i -= minus;
		res += minus;
	}
	return (res);
}

static int		print_all_word(wchar_t *str)
{
	int			res;

	res = 0;
	while (*str)
	{
		res += printer_for_wchar(*str);
		str++;
	}
	return (res);
}

static int		print_spec(t_spe **t, wchar_t *str, int size, int spe)
{
	int			j;
	int			c;

	j = 0;
	c = 0;
	if ((*t)->minus)
	{
		((spe) ? (j = print_all_word_spe(t, str))
		: (j = print_all_word(str)));
		c = second_word(t, size, str, spe);
	}
	if (!(*t)->minus)
	{
		c = first_word(t, size, str, spe);
		((spe) ? (j = print_all_word_spe(t, str))
		: (j = print_all_word(str)));
	}
	return (c + j);
}

int				printer_to_wch_s(t_spe **t, wchar_t *str)
{
	if (!str)
		return (printall(create_null(), t, (*t)->size));
	if ((*t)->size_spec != 0 || (*t)->pointer)
	{
		if ((*t)->pointer && (*t)->size_spec <= 1)
			(*t)->size_spec = 0;
		return (print_spec(t, str, (*t)->size_spec, 1));
	}
	else
		return (print_spec(t, str, str_w_length(str), 0));
}

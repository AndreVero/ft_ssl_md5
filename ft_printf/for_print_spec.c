/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:54:08 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:26:06 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int					how_many_char(wchar_t c)
{
	if (c <= 0x7f)
		return (1);
	if (c > 0x7f && c <= 0x7ff)
		return (2);
	if (c > 0x7ff && c <= 0xffff)
		return (3);
	else
		return (4);
}

static int			count_symb_spe(wchar_t *str, t_spe **t)
{
	int				i;
	int				j;
	int				res;
	int				minus;

	res = 0;
	minus = 0;
	j = str_w_length(str);
	i = (*t)->size_spec;
	while (j < i)
	{
		j++;
		res++;
	}
	while (*str && i > 0 && (i - minus) > 0)
	{
		minus = how_many_char(*str);
		str++;
		i -= minus;
		res += minus;
	}
	return (res);
}

static int			count_symb(wchar_t *str)
{
	int				res;

	res = 0;
	while (*str)
	{
		res += how_many_char(*str);
		str++;
	}
	return (res);
}

int					first_word(t_spe **t, int size, wchar_t *str, int spe)
{
	int				c;
	int				j;

	c = 0;
	((spe) ? (j = count_symb_spe(str, t)) :
	(j = count_symb(str)));
	while ((*t)->size > j)
	{
		(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
		c++;
		size++;
		j++;
	}
	return (c);
}

int					second_word(t_spe **t, int size, wchar_t *str, int spe)
{
	int				c;
	int				j;

	c = 0;
	((spe) ? (j = count_symb_spe(str, t)) :
	(j = count_symb(str)));
	while ((*t)->size > j)
	{
		(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
		c++;
		size++;
		j++;
	}
	return (c);
}

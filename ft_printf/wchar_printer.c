/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:36:57 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/05 19:28:32 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int				find_right_print_for_wch(char *arr, wchar_t c, int size)
{
	if (size == 1)
	{
		arr[0] = (c >> 6) + 0xc0;
		arr[1] = (c & 0x3f) + 0x80;
		write(1, arr, 2);
		return (2);
	}
	else if (size == 2)
	{
		arr[0] = (c >> 12) + 0xe0;
		arr[1] = ((c >> 6) & 0x3f) + 0x80;
		arr[2] = (c & 0x3f) + 0x80;
		write(1, arr, 3);
		return (3);
	}
	else if (size == 3)
	{
		arr[0] = (c >> 16) + 0xf0;
		arr[1] = ((c >> 12) & 0x3f) + 0x80;
		arr[2] = ((c >> 6) & 0x3f) + 0x80;
		arr[3] = (c & 0x3f) + 0x80;
		write(1, arr, 4);
		return (4);
	}
	return (1);
}

int						printer_for_wchar(wchar_t d)
{
	char				arr[4];
	wchar_t				c;

	c = d;
	if (c <= 0x7f)
		write(1, &c, 1);
	else if (c > 0x7f && c <= 0x7ff)
		return (find_right_print_for_wch(arr, c, 1));
	else if (c > 0x7ff && c <= 0xffff)
		return (find_right_print_for_wch(arr, c, 2));
	else
		return (find_right_print_for_wch(arr, c, 3));
	return (1);
}

static int				c_printer(t_spe **t, char d)
{
	int					j;

	j = 0;
	if ((*t)->minus)
	{
		write(1, &d, 1);
		while (j++ < (*t)->size - 1)
			(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
	}
	if (!((*t)->minus))
	{
		while (j++ < (*t)->size - 1)
			(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
		write(1, &d, 1);
	}
	return (j);
}

int						print_right_wch(t_spe **t, wchar_t d)
{
	int					i;
	int					j;
	char				tmp;

	i = 0;
	j = 0;
	if ((*t)->symb == 'c' && ft_strcmp((*t)->size_mdf, "l"))
	{
		tmp = (char)d;
		return (c_printer(t, tmp));
	}
	else if ((*t)->minus)
	{
		j = printer_for_wchar(d);
		while (i++ < (*t)->size - 1)
			(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
	}
	else if (!((*t)->minus))
	{
		while (i++ < (*t)->size - 1)
			(((*t)->zero) ? ft_putchar('0') : ft_putchar(' '));
		j = printer_for_wchar(d);
	}
	return (i + j - 1);
}

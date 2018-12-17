/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octat_to_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:39:27 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:05:26 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int					zero_time(t_spe **t)
{
	if ((*t)->size > 0)
		return (printall(m(ft_strdup(" "), (*t)->size_spec), t, (*t)->size));
	else
		return (printall(m(ft_strdup(""), (*t)->size_spec), t, (*t)->size));
}

static char					*make_oct(t_spe **t, char *res, char *str_to)
{
	int			size;
	char		*str;
	char		*str1;
	char		*str2;

	size = (*t)->size_spec - ft_strlen(res);
	str1 = m(str_to, size);
	str2 = ft_reverse(res);
	str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str);
}

int							dec_to_oct(t_spe **t, unsigned long long int d)
{
	char					res[1000];
	char					*str_to_m;
	int						i;

	i = 0;
	ft_bzero(res, 100);
	if (d == 0 && (*t)->pointer && !(*t)->hash)
		return (zero_time(t));
	if (d == 0)
		return (printall(ft_strdup("0"), t, (*t)->size));
	while (d != 0)
	{
		res[i++] = ((d % 8) + '0');
		d = d / 8;
	}
	if ((*t)->hash && !(*t)->zero)
	{
		str_to_m = ft_strnew(1);
		*str_to_m = '0';
		(*t)->size_spec--;
	}
	else
		str_to_m = ft_strnew(1);
	return (printall(make_oct(t, res, str_to_m), t, (*t)->size));
}

static char					*make_right_hex(t_spe **t, char *str)
{
	char					*str_to_hex;
	char					*res;
	int						size;
	int						i;
	char					*str1;

	i = 0;
	str_to_hex = ft_strnew(2);
	if ((*t)->hash && !(*t)->zero)
	{
		str_to_hex[0] = '0';
		str_to_hex[1] = 'x';
	}
	size = (*t)->size_spec - ft_strlen(str);
	str1 = m(str_to_hex, size);
	res = ft_strjoin(str1, str);
	freesher_for_2(str1, str);
	if ((*t)->symb == 'X')
		while (res[i] != '\0')
		{
			res[i] = ft_toupper(res[i]);
			i++;
		}
	return (res);
}

int							decimal_to_hex(t_spe **t, unsigned long long int d)
{
	char					*p;
	char					*help_str;

	if (d == 0 && (*t)->pointer)
		return (zero_time(t));
	if (d == 0)
		return (printall(ft_strdup("0"), t, (*t)->size));
	help_str = help_hex(d);
	p = ft_reverse(help_str);
	free(help_str);
	if ((*t)->hash && (*t)->zero)
	{
		write(2, "0x", 2);
		(*t)->size = (*t)->size - 2;
		(*t)->output = (*t)->size_spec - ft_strlen(p);
		return (printall(m(p, (*t)->output), t, (*t)->size) + 2);
	}
	else
		return (printall(make_right_hex(t, p), t, (*t)->size));
}

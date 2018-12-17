/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_for_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:46:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:10:54 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char							*to_hex(unsigned long long int d)
{
	char						res[1000];
	unsigned long long int		del;
	int							i;
	char						*p;

	i = 0;
	ft_bzero(res, 1000);
	if (d == 0)
	{
		res[i] = '0';
		i++;
	}
	while (d != 0)
	{
		del = d % 16;
		res[i] = findsymb(del);
		d /= 16;
		i++;
	}
	p = ft_reverse(res);
	return (p);
}

static int						count_mistake(int j, int i)
{
	int							k;

	k = 0;
	while (i++ < 0)
		k++;
	return (j - k);
}

static char						*print_with_zero(t_spe **t, char *str)
{
	int							i;
	int							j;
	char						*s;
	int							k;
	char						*res;

	k = 0;
	j = 0;
	i = (*t)->size_spec;
	while (i-- > (int)ft_strlen(str))
		j++;
	j = count_mistake(j, i) - 1;
	if (j > 0)
	{
		s = ft_strnew(j);
		while (k < j)
			s[k++] = '0';
	}
	else
		s = ft_strnew(1);
	res = ft_strjoin(s, str);
	free(s);
	free(str);
	return (res);
}

int								print_for_memory(t_spe **t, void **tmp)
{
	unsigned long long			res;
	char						*str;
	char						*test;

	if (!tmp && (*t)->pointer && (*t)->size_spec <= 1)
		return (printall_p(ft_strdup(""), t, (*t)->size + 2) + 2);
	res = (unsigned long long)&(*tmp);
	str = to_hex(res);
	if ((*t)->size_spec > 0)
	{
		test = print_with_zero(t, str);
		return (printall_p(test, t, (*t)->size) + 2);
	}
	else
		test = str;
	return (printall_p(test, t, (*t)->size) + 2);
}

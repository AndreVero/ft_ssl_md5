/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:33:54 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:17:42 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char				*create_null(void)
{
	char			*str;

	str = ft_strnew(6);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	return (str);
}

int					print_zero_str(t_spe **t)
{
	int				i;

	i = 0;
	while (i++ < (*t)->size)
		(*t)->zero ? write(1, "0", 1) : write(1, " ", 1);
	return ((*t)->size);
}

int					str_printer(t_spe **t, char *str)
{
	char			*res;
	int				i;

	i = 0;
	res = NULL;
	if (!str && (*t)->size_spec > 0)
		return (print_zero_str(t));
	if (!str)
		return (printall(create_null(), t, (*t)->size));
	if ((*t)->size_spec != 0)
	{
		res = ft_strnew((*t)->size_spec - 1);
		if (!res)
			return (0);
		while (i < (*t)->size_spec - 1)
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	else
		res = ft_strdup(str);
	return (printall(res, t, (*t)->size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:12:39 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:24:51 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int						uint_printer(t_spe **t, unsigned long long c)
{
	char				*res;
	char				*res1;
	char				*for_free;
	unsigned long long	count;
	char				*number;

	if (!ft_strcmp((*t)->size_mdf, "hh") && (*t)->symb == 'u')
		count = (unsigned char)c;
	else if (!ft_strcmp((*t)->size_mdf, "hh") && (*t)->symb == 'U')
		count = (unsigned short)c;
	else if (!ft_strcmp((*t)->size_mdf, "l") && (*t)->symb == 'u')
		count = c;
	else if (!ft_strcmp((*t)->size_mdf, "\0") && !((*t)->symb == 'U'))
		count = (unsigned int)c;
	else
		count = (unsigned long long)c;
	if (c == 0 && (*t)->pointer)
		return (printall(ft_strdup(""), t, (*t)->size));
	for_free = ft_strnew(1);
	number = ft_utoal(count);
	res1 = m(for_free, (*t)->size_spec - ft_strlen(number));
	res = ft_strjoin(res1, number);
	free(res1);
	free(number);
	return (printall(res, t, (*t)->size));
}

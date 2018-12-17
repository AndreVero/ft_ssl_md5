/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 03:35:04 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:22:09 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char		*make_int_minus(t_spe **t, long long int c)
{
	char	*res;
	char	*res1;
	char	*s1;

	res = ft_itoal(-c);
	(*t)->size = (*t)->size - 1;
	s1 = ft_itoal(c);
	res1 = (m(res, (*t)->size_spec - ft_strlen(s1)));
	free(s1);
	return (res1);
}

char		*make_int_plus(t_spe **t, long long int c)
{
	char	*res;
	char	*res1;

	res = ft_itoal(c);
	(*t)->size = (*t)->size - 1;
	res1 = (m(res, (*t)->size_spec - ft_strlen(res)));
	return (res1);
}

char		*make_int_space(t_spe **t, long long int c)
{
	char	*res;
	char	*res1;

	res = ft_itoal(c);
	(*t)->size = (*t)->size - 1;
	res1 = (m(res, (*t)->size_spec - ft_strlen(res)));
	return (res1);
}

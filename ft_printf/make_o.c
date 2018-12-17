/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 01:59:17 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/04 04:06:11 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int			make_o(t_spe **t, unsigned long long int d)
{
	if (!ft_strcmp((*t)->size_mdf, "hh"))
		return (dec_to_oct(t, (unsigned char)d));
	if (!ft_strcmp((*t)->size_mdf, "h"))
		return (dec_to_oct(t, (unsigned short)d));
	if (!ft_strcmp((*t)->size_mdf, "\0"))
		return (dec_to_oct(t, (unsigned int)d));
	else
		return (dec_to_oct(t, d));
}

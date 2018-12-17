/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 02:30:11 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/05 19:49:00 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int			make_h(t_spe **t, unsigned long long int d)
{
	if (!ft_strcmp((*t)->size_mdf, "h"))
		return (decimal_to_hex(t, (unsigned short int)d));
	if (!ft_strcmp((*t)->size_mdf, "hh"))
		return (decimal_to_hex(t, (unsigned char)d));
	if (!ft_strcmp((*t)->size_mdf, "\0"))
		return (decimal_to_hex(t, (unsigned int)d));
	else
		return (decimal_to_hex(t, d));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:13:24 by averemiy          #+#    #+#             */
/*   Updated: 2018/04/27 00:20:07 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void		print_null(t_spe **t)
{
	if ((*t)->minus)
	{
		ft_putstr("(null)");
		while ((*t)->size > 6)
		{
			((*t)->zero) ? ft_putchar('0') : ft_putchar(' ');
			(*t)->size--;
		}
	}
	else
	{
		while ((*t)->size > 6)
		{
			((*t)->zero) ? ft_putchar('0') : ft_putchar(' ');
			(*t)->size--;
		}
		ft_putstr("(null)");
	}
	return ;
}

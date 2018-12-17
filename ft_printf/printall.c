/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:26:28 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:08:16 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int				printall(char *str, t_spe **t, int s)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	if ((*t)->minus)
	{
		ft_putstr(str);
		while (i++ < s - (int)ft_strlen(str))
			ft_putchar(' ');
	}
	if (!((*t)->minus))
	{
		while (i++ < s - (int)ft_strlen(str))
			(((*t)->zero && (*t)->size_spec <= 0) ?
			ft_putchar('0') : ft_putchar(' '));
		ft_putstr(str);
	}
	size = ft_strlen(str);
	free(str);
	return (i + size - 1);
}

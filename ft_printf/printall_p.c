/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:28:27 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:23:06 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int		print_for_rigth(char *str, t_spe **t, int s)
{
	int i;

	i = 0;
	while (i++ < s - (int)ft_strlen(str) - 2)
		(((*t)->zero && (*t)->size_spec <= 0) ?
		ft_putchar('0') : ft_putchar(' '));
	write(1, "0x", 2);
	ft_putstr(str);
	return (i);
}

int				printall_p(char *str, t_spe **t, int s)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	if (!(*t)->minus && (*t)->size_spec <= 0 && (*t)->zero)
	{
		write(1, "0x", 2);
		while (i++ < s - (int)ft_strlen(str) - 2)
			ft_putchar('0');
		ft_putstr(str);
	}
	else if ((*t)->minus)
	{
		write(1, "0x", 2);
		ft_putstr(str);
		while (i++ < s - (int)ft_strlen(str) - 2)
			(((*t)->zero && (*t)->size_spec <= 0) ?
			ft_putchar('0') : ft_putchar(' '));
	}
	else if (!((*t)->minus))
		i = print_for_rigth(str, t, s);
	size = ft_strlen(str);
	free(str);
	return (i + size - 1);
}

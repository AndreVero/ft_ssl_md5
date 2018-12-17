/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:17:33 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/05 20:11:35 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdarg.h>

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	int				result;

	if (!str)
	{
		exit(0);
		return (0);
	}
	result = 0;
	va_start(ap, str);
	result = find_rigth_solve((char *)str, ap);
	va_end(ap);
	return (result);
}

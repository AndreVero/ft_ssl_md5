/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:53:31 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:05:11 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char						*help_hex(unsigned long long int d)
{
	char					*res;
	unsigned long long int	del;
	int						i;

	i = 0;
	res = ft_strnew(1000);
	while (d != 0)
	{
		del = d % 16;
		res[i++] = findsymb(del);
		d /= 16;
	}
	res[i] = '\0';
	return (res);
}

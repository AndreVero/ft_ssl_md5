/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsymb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:59:06 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/02 21:03:28 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	findsymb(unsigned long long int del)
{
	if (del >= 10)
	{
		if (del == 10)
			return ('a');
		if (del == 11)
			return ('b');
		if (del == 12)
			return ('c');
		if (del == 13)
			return ('d');
		if (del == 14)
			return ('e');
		if (del == 15)
			return ('f');
	}
	return (del + '0');
}

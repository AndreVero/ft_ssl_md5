/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:55:58 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/05 18:37:02 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int					sch(long long n)
{
	long long				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void					smth(char *s, long long n, long long l)
{
	long long				res;
	long long				del;
	long long				n1;

	res = 0;
	while (l > 0)
	{
		del = l - 1;
		n1 = n;
		res = n1;
		while (del > 0)
		{
			res = n1 / 10;
			n1 = n1 / 10;
			del--;
		}
		res = res % 10;
		*s = res + '0';
		l--;
		s++;
	}
	*s = '\0';
}

static char					*memus(int i, long long n)
{
	char					*res;
	long long				size;
	char					*p;

	if (i > 1)
	{
		size = sch(-1 * n);
		res = ft_strnew(size + 1);
		if (res == NULL)
			return (NULL);
		p = res;
		*res = '-';
		res++;
		smth(res, (-1 * n), size);
	}
	else
	{
		size = sch(n);
		res = ft_strnew(size);
		if (res == NULL)
			return (NULL);
		p = res;
		smth(res, n, size);
	}
	return (p);
}

char						*ft_itoal(long long int n)
{
	char					*res;

	res = NULL;
	if (((n + 9223372036854775800) + 8) == 0)
		return (ft_strdup("9223372036854775808"));
	else if (n < 0)
		res = memus(2, n);
	else
		res = memus(1, n);
	return (res);
}

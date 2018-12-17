/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:15:25 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 14:45:04 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int					sch(unsigned long long n)
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

static void					smth(char *s, unsigned long long n, long long l)
{
	unsigned long long				res;
	unsigned long long				del;
	unsigned long long				n1;

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

static char					*memus(unsigned long long n)
{
	char					*res;
	unsigned long long		size;
	char					*p;

	size = sch(n);
	res = ft_strnew(size);
	if (res == NULL)
		return (NULL);
	p = res;
	smth(res, n, size);
	return (p);
}

char						*ft_utoal(unsigned long long int n)
{
	char					*res;

	if ((((n - 446744073709551615) - 9000000000000000000)
				- 9000000000000000000) == 0)
		return (ft_strdup("18446744073709551615"));
	res = NULL;
	res = memus(n);
	return (res);
}

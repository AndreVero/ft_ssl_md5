/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 20:01:41 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/26 20:13:53 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int							ft_un_strlen(unsigned char *str)
{
	int								res;

	res = 0;
	while (*str != '\0')
	{
		res++;
		str++;
	}
	return (res);
}

static unsigned char				*add_str(unsigned char *s, \
		int i, unsigned char c)
{
	unsigned char					*str;
	int								j;
	unsigned char					*s1;

	j = 0;
	s1 = s;
	str = (unsigned char *)malloc(sizeof(unsigned char) * i + 2);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	if (c == 0)
		free(s1);
	s1 = NULL;
	str[j++] = c;
	str[j] = '\0';
	return (str);
}

static unsigned long long int		from_8_byte_to_int(int i,\
		unsigned char *str)
{
	char		arr[8];

	arr[7] = str[i];
	arr[6] = str[i + 1];
	arr[5] = str[i + 2];
	arr[4] = str[i + 3];
	arr[3] = str[i + 4];
	arr[2] = str[i + 5];
	arr[1] = str[i + 6];
	arr[0] = str[i + 7];
	return (*(unsigned long long int*)(arr));
}

static unsigned long long int		*create_to_64(unsigned char *str,\
		int len)
{
	unsigned long long int			*test;
	int								i;
	int								j;

	i = 0;
	j = 0;
	test = (unsigned long long int *)malloc(sizeof(unsigned long long int *)\
			* (len / 8));
	while (i < len)
	{
		test[j] = from_8_byte_to_int(i, str);
		i += 8;
		j++;
	}
	return (test);
}

void								hash_sha512(t_alg *alg)
{
	unsigned char					*str;
	int								len;
	unsigned long long int			*test;
	unsigned long long int			len_bit;

	len = ft_un_strlen(alg->str);
	len_bit = len * 8;
	str = add_str(alg->str, len++, (unsigned char)128);
	while (len % 128 != 120)
	{
		str = add_str(str, len, (unsigned char)0);
		len++;
	}
	add_length_sha512(str, len, len_bit);
	len += 8;
	test = create_to_64(str, len);
	create_hash_sha512(test, len, alg);
	free(str);
	free(test);
	alg->str = NULL;
}

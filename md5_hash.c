/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:56:25 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 13:40:51 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int							ft_un_strlen(unsigned char *str)
{
	int						res;

	res = 0;
	while (*str != '\0')
	{
		res++;
		str++;
	}
	return (res);
}

unsigned char				*add_str(unsigned char *s, \
		int i, unsigned char c)
{
	unsigned char			*str;
	int						j;
	unsigned char			*s1;

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

static unsigned int			from_4_byte_to_int(int i, unsigned char *str)
{
	char					arr[4];

	arr[0] = str[i];
	arr[1] = str[i + 1];
	arr[2] = str[i + 2];
	arr[3] = str[i + 3];
	return (*(unsigned int*)(arr));
}

unsigned int				*create_to_32(unsigned char *str, int len)
{
	unsigned int			*test;
	int						i;
	int						j;

	i = 0;
	j = 0;
	test = (unsigned int *)malloc(sizeof(unsigned int *) * (len / 4));
	while (i < len)
	{
		test[j] = from_4_byte_to_int(i, str);
		i += 4;
		j++;
	}
	return (test);
}

void						hash_md5(t_alg *alg)
{
	unsigned char			*str;
	int						len;
	unsigned int			*test;
	unsigned long long int	len_bit;

	len = ft_un_strlen(alg->str);
	len_bit = len * 8;
	str = add_str(alg->str, len++, (unsigned char)128);
	while (len % 64 != 56)
	{
		str = add_str(str, len, (unsigned char)0);
		len++;
	}
	add_length_md5(str, len, len_bit);
	len += 8;
	test = create_to_32(str, len);
	create_hash_md5(test, len, alg);
	free(str);
	free(test);
}

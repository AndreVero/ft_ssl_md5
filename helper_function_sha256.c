/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function_sha256.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:32:37 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/26 19:33:39 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int				rotr(unsigned int res, int bitwise_cicle_right)
{
	return (res >> bitwise_cicle_right | res << (32 - bitwise_cicle_right));
}

void						add_length_sha(unsigned char *test, \
		int l, unsigned long long int len)
{
	int						i;

	i = 7;
	while (i >= 0)
	{
		test[l++] = (unsigned char)(len >> i * 8);
		i--;
	}
}

static void					hash_one(unsigned int i)
{
	unsigned char			bytes[4];
	int						j;

	j = -1;
	bytes[0] = (i >> 24) & 0xFF;
	bytes[1] = (i >> 16) & 0xFF;
	bytes[2] = (i >> 8) & 0xFF;
	bytes[3] = i & 0xFF;
	while (++j < 4)
		ft_printf("%02x", bytes[j]);
}

void						print_256(t_sha_data *data)
{
	hash_one(data->h0);
	hash_one(data->h1);
	hash_one(data->h2);
	hash_one(data->h3);
	hash_one(data->h4);
	hash_one(data->h5);
	hash_one(data->h6);
	hash_one(data->h7);
}

void						init_data_256(t_sha_data *data)
{
	data->a = data->h0;
	data->b = data->h1;
	data->c = data->h2;
	data->d = data->h3;
	data->e = data->h4;
	data->f = data->h5;
	data->g = data->h6;
	data->h = data->h7;
}

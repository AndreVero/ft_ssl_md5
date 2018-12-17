/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function_sha512.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:32:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/26 19:32:46 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned long long int			rotr512(unsigned long long int res, \
		int bitwise_cicle_right)
{
	return (res >> bitwise_cicle_right | res << (64 - bitwise_cicle_right));
}

void							add_length_sha512(unsigned char *test, \
		int l, unsigned long long int len)
{
	int					i;

	i = 7;
	while (i >= 0)
	{
		test[l++] = (unsigned char)(len >> i * 8);
		i--;
	}
}

void							init_data512(t_sha_data512 *data)
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

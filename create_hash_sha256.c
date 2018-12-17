/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash_sha256.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:40:36 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/26 20:15:37 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdlib.h>

static void			init_data(t_sha_data *tmp)
{
	tmp->h0 = 0x6A09E667;
	tmp->h1 = 0xBB67AE85;
	tmp->h2 = 0x3C6EF372;
	tmp->h3 = 0xA54FF53A;
	tmp->h4 = 0x510E527F;
	tmp->h5 = 0x9B05688C;
	tmp->h6 = 0x1F83D9AB;
	tmp->h7 = 0x5BE0CD19;
}

static void			add_data(t_sha_data *tmp)
{
	tmp->h = tmp->g;
	tmp->g = tmp->f;
	tmp->f = tmp->e;
	tmp->e = tmp->d + tmp->t1;
	tmp->d = tmp->c;
	tmp->c = tmp->b;
	tmp->b = tmp->a;
	tmp->a = tmp->t1 + tmp->t2;
}

static void			main_sha_cicle(t_sha_data *tmp, unsigned int *w)
{
	int				i;

	i = -1;
	while (++i < 64)
	{
		tmp->z0 = rotr(tmp->a, 2) ^ rotr(tmp->a, 13) ^ rotr(tmp->a, 22);
		tmp->ma = (tmp->a & tmp->b) ^ (tmp->a & tmp->c) ^ (tmp->b & tmp->c);
		tmp->t2 = tmp->z0 + tmp->ma;
		tmp->z1 = rotr(tmp->e, 6) ^ rotr(tmp->e, 11) ^ rotr(tmp->e, 25);
		tmp->ch = (tmp->e & tmp->f) ^ ((~tmp->e) & tmp->g);
		tmp->t1 = tmp->h + tmp->z1 + tmp->ch + g_k[i] + w[i];
		add_data(tmp);
	}
	tmp->h0 += tmp->a;
	tmp->h1 += tmp->b;
	tmp->h2 += tmp->c;
	tmp->h3 += tmp->d;
	tmp->h4 += tmp->e;
	tmp->h5 += tmp->f;
	tmp->h6 += tmp->g;
	tmp->h7 += tmp->h;
}

static void			init_add_array(unsigned int *w, unsigned int *tmp, int i)
{
	int				j;
	unsigned int	s0;
	unsigned int	s1;

	j = -1;
	while (++j < 16)
		w[j] = tmp[i++];
	while (j < 64)
	{
		s0 = rotr(w[j - 15], 7) ^ rotr(w[j - 15], 18) ^
			(w[j - 15] >> 3);
		s1 = rotr(w[j - 2], 17) ^ rotr(w[j - 2], 19) ^
			(w[j - 2] >> 10);
		w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		j++;
	}
}

void				create_hash_sha256(unsigned int *tmp, int len, t_alg *alg)
{
	t_sha_data		*data;
	int				i;
	unsigned int	*w;

	i = 0;
	w = (unsigned int *)malloc(sizeof(unsigned int) * 64);
	data = (t_sha_data *)malloc(sizeof(t_sha_data));
	init_data(data);
	while (i < len / 4)
	{
		init_data_256(data);
		init_add_array(w, tmp, i);
		main_sha_cicle(data, w);
		i += 16;
	}
	print_256(data);
	free(data);
	free(w);
	if (!alg->r)
		ft_printf("\n");
}

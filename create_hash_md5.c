/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash_md5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:27:03 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 14:38:33 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void					add_length_md5(unsigned char *test, \
		int l, unsigned long long int len)
{
	int					i;

	i = 0;
	while (i < 8)
	{
		test[l++] = (unsigned char)(len >> i * 8);
		i++;
	}
}

static void				init_helper(t_abcdt *test)
{
	test->a = 0x67452301;
	test->b = 0xefcdab89;
	test->c = 0x98badcfe;
	test->d = 0x10325476;
}

static void				hash_one(unsigned int i)
{
	unsigned char		bytes[4];
	int					j;

	j = -1;
	bytes[3] = (i >> 24) & 0xFF;
	bytes[2] = (i >> 16) & 0xFF;
	bytes[1] = (i >> 8) & 0xFF;
	bytes[0] = i & 0xFF;
	while (++j < 4)
		ft_printf("%02x", bytes[j]);
}

static void				print_hash(t_abcdt *t, t_alg *alg)
{
	hash_one(t->a);
	hash_one(t->b);
	hash_one(t->c);
	hash_one(t->d);
	if (!alg->r)
		ft_printf("\n");
}

void					create_hash_md5(unsigned int *test, int l, t_alg *alg)
{
	t_abcdt *tmp;
	int		i;

	i = 0;
	tmp = (t_abcdt *)malloc(sizeof(t_abcdt));
	init_helper(tmp);
	while (i < l / 4)
	{
		tmp->aa = tmp->a;
		tmp->bb = tmp->b;
		tmp->cc = tmp->c;
		tmp->dd = tmp->d;
		main_round_1(tmp, i, test);
		main_round_2(tmp, i, test);
		main_round_3(tmp, i, test);
		main_round_4(tmp, i, test);
		tmp->a = tmp->aa + tmp->a;
		tmp->b = tmp->bb + tmp->b;
		tmp->c = tmp->cc + tmp->c;
		tmp->d = tmp->dd + tmp->d;
		i += 16;
	}
	print_hash(tmp, alg);
	free(tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:24:37 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 15:38:43 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

typedef struct		s_alg
{
	int				cript;
	int				r;
	int				p;
	int				q;
	int				s;
	int				std;
	unsigned char	*str;
}					t_alg;

typedef	struct		s_abcdt
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	aa;
	unsigned int	bb;
	unsigned int	cc;
	unsigned int	dd;
}					t_abcdt;

static unsigned int	g_t[64] =
{
	0xD76AA478, 0xE8C7B756, 0x242070DB, 0xC1BDCEEE, 0xF57C0FAF,
	0x4787C62A, 0xA8304613, 0xFD469501, 0x698098D8, 0x8B44F7AF,
	0xFFFF5BB1, 0x895CD7BE, 0x6B901122, 0xFD987193, 0xA679438E,
	0x49B40821, 0xF61E2562, 0xC040B340, 0x265E5A51, 0xE9B6C7AA,
	0xD62F105D, 0x2441453, 0xD8A1E681, 0xE7D3FBC8, 0x21E1CDE6,
	0xC33707D6, 0xF4D50D87, 0x455A14ED, 0xA9E3E905, 0xFCEFA3F8,
	0x676F02D9, 0x8D2A4C8A, 0xFFFA3942, 0x8771F681, 0x6D9D6122,
	0xFDE5380C, 0xA4BEEA44, 0x4BDECFA9, 0xF6BB4B60, 0xBEBFBC70,
	0x289B7EC6, 0xEAA127FA, 0xD4EF3085, 0x4881D05, 0xD9D4D039,
	0xE6DB99E5, 0x1FA27CF8, 0xC4AC5665, 0xF4292244, 0x432AFF97,
	0xAB9423A7, 0xFC93A039, 0x655B59C3, 0x8F0CCC92, 0xFFEFF47D,
	0x85845DD1, 0x6FA87E4F, 0xFE2CE6E0, 0xA3014314, 0x4E0811A1,
	0xF7537E82, 0xBD3AF235, 0x2AD7D2BB, 0xEB86D391
};

void				hash_md5(t_alg *alg);
void				add_length_md5(unsigned char *test, int l, \
	unsigned long long int len);
void				create_hash_md5(unsigned int *tmp, int len, t_alg *alg);
void				main_round_1(t_abcdt *tmp, int i, unsigned int *test);
unsigned int		f_f(unsigned int x, unsigned int y, unsigned int z);
unsigned int		f_g(unsigned int x, unsigned int y, unsigned int z);
unsigned int		f_h(unsigned int x, unsigned int y, unsigned int z);
unsigned int		f_i(unsigned int x, unsigned int y, unsigned int z);
void				main_round_2(t_abcdt *tmp, int i, unsigned int *test);
void				main_round_3(t_abcdt *tmp, int i, unsigned int *test);
void				main_round_4(t_abcdt *tmp, int i, unsigned int *test);

#endif

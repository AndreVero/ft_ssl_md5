/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:56 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 14:44:27 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	b_c(unsigned int res, int bitwise_cicle_left)
{
	return (res << bitwise_cicle_left | res >> (32 - bitwise_cicle_left));
}

void			main_round_1(t_abcdt *t, int i, unsigned int *s)
{
	t->a = t->b + b_c((t->a + f_f(t->b, t->c, t->d) + s[i + 0] + g_t[0]), 7);
	t->d = t->a + b_c((t->d + f_f(t->a, t->b, t->c) + s[i + 1] + g_t[1]), 12);
	t->c = t->d + b_c((t->c + f_f(t->d, t->a, t->b) + s[i + 2] + g_t[2]), 17);
	t->b = t->c + b_c((t->b + f_f(t->c, t->d, t->a) + s[i + 3] + g_t[3]), 22);
	t->a = t->b + b_c((t->a + f_f(t->b, t->c, t->d) + s[i + 4] + g_t[4]), 7);
	t->d = t->a + b_c((t->d + f_f(t->a, t->b, t->c) + s[i + 5] + g_t[5]), 12);
	t->c = t->d + b_c((t->c + f_f(t->d, t->a, t->b) + s[i + 6] + g_t[6]), 17);
	t->b = t->c + b_c((t->b + f_f(t->c, t->d, t->a) + s[i + 7] + g_t[7]), 22);
	t->a = t->b + b_c((t->a + f_f(t->b, t->c, t->d) + s[i + 8] + g_t[8]), 7);
	t->d = t->a + b_c((t->d + f_f(t->a, t->b, t->c) + s[i + 9] + g_t[9]), 12);
	t->c = t->d + b_c((t->c + f_f(t->d, t->a, t->b) + s[i + 10] + g_t[10]), 17);
	t->b = t->c + b_c((t->b + f_f(t->c, t->d, t->a) + s[i + 11] + g_t[11]), 22);
	t->a = t->b + b_c((t->a + f_f(t->b, t->c, t->d) + s[i + 12] + g_t[12]), 7);
	t->d = t->a + b_c((t->d + f_f(t->a, t->b, t->c) + s[i + 13] + g_t[13]), 12);
	t->c = t->d + b_c((t->c + f_f(t->d, t->a, t->b) + s[i + 14] + g_t[14]), 17);
	t->b = t->c + b_c((t->b + f_f(t->c, t->d, t->a) + s[i + 15] + g_t[15]), 22);
}

void			main_round_2(t_abcdt *t, int i, unsigned int *s)
{
	t->a = t->b + b_c((t->a + f_g(t->b, t->c, t->d) + s[i + 1] + g_t[16]), 5);
	t->d = t->a + b_c((t->d + f_g(t->a, t->b, t->c) + s[i + 6] + g_t[17]), 9);
	t->c = t->d + b_c((t->c + f_g(t->d, t->a, t->b) + s[i + 11] + g_t[18]), 14);
	t->b = t->c + b_c((t->b + f_g(t->c, t->d, t->a) + s[i + 0] + g_t[19]), 20);
	t->a = t->b + b_c((t->a + f_g(t->b, t->c, t->d) + s[i + 5] + g_t[20]), 5);
	t->d = t->a + b_c((t->d + f_g(t->a, t->b, t->c) + s[i + 10] + g_t[21]), 9);
	t->c = t->d + b_c((t->c + f_g(t->d, t->a, t->b) + s[i + 15] + g_t[22]), 14);
	t->b = t->c + b_c((t->b + f_g(t->c, t->d, t->a) + s[i + 4] + g_t[23]), 20);
	t->a = t->b + b_c((t->a + f_g(t->b, t->c, t->d) + s[i + 9] + g_t[24]), 5);
	t->d = t->a + b_c((t->d + f_g(t->a, t->b, t->c) + s[i + 14] + g_t[25]), 9);
	t->c = t->d + b_c((t->c + f_g(t->d, t->a, t->b) + s[i + 3] + g_t[26]), 14);
	t->b = t->c + b_c((t->b + f_g(t->c, t->d, t->a) + s[i + 8] + g_t[27]), 20);
	t->a = t->b + b_c((t->a + f_g(t->b, t->c, t->d) + s[i + 13] + g_t[28]), 5);
	t->d = t->a + b_c((t->d + f_g(t->a, t->b, t->c) + s[i + 2] + g_t[29]), 9);
	t->c = t->d + b_c((t->c + f_g(t->d, t->a, t->b) + s[i + 7] + g_t[30]), 14);
	t->b = t->c + b_c((t->b + f_g(t->c, t->d, t->a) + s[i + 12] + g_t[31]), 20);
}

void			main_round_3(t_abcdt *t, int i, unsigned int *s)
{
	t->a = t->b + b_c((t->a + f_h(t->b, t->c, t->d) + s[i + 5] + g_t[32]), 4);
	t->d = t->a + b_c((t->d + f_h(t->a, t->b, t->c) + s[i + 8] + g_t[33]), 11);
	t->c = t->d + b_c((t->c + f_h(t->d, t->a, t->b) + s[i + 11] + g_t[34]), 16);
	t->b = t->c + b_c((t->b + f_h(t->c, t->d, t->a) + s[i + 14] + g_t[35]), 23);
	t->a = t->b + b_c((t->a + f_h(t->b, t->c, t->d) + s[i + 1] + g_t[36]), 4);
	t->d = t->a + b_c((t->d + f_h(t->a, t->b, t->c) + s[i + 4] + g_t[37]), 11);
	t->c = t->d + b_c((t->c + f_h(t->d, t->a, t->b) + s[i + 7] + g_t[38]), 16);
	t->b = t->c + b_c((t->b + f_h(t->c, t->d, t->a) + s[i + 10] + g_t[39]), 23);
	t->a = t->b + b_c((t->a + f_h(t->b, t->c, t->d) + s[i + 13] + g_t[40]), 4);
	t->d = t->a + b_c((t->d + f_h(t->a, t->b, t->c) + s[i + 0] + g_t[41]), 11);
	t->c = t->d + b_c((t->c + f_h(t->d, t->a, t->b) + s[i + 3] + g_t[42]), 16);
	t->b = t->c + b_c((t->b + f_h(t->c, t->d, t->a) + s[i + 6] + g_t[43]), 23);
	t->a = t->b + b_c((t->a + f_h(t->b, t->c, t->d) + s[i + 9] + g_t[44]), 4);
	t->d = t->a + b_c((t->d + f_h(t->a, t->b, t->c) + s[i + 12] + g_t[45]), 11);
	t->c = t->d + b_c((t->c + f_h(t->d, t->a, t->b) + s[i + 15] + g_t[46]), 16);
	t->b = t->c + b_c((t->b + f_h(t->c, t->d, t->a) + s[i + 2] + g_t[47]), 23);
}

void			main_round_4(t_abcdt *t, int i, unsigned int *s)
{
	t->a = t->b + b_c((t->a + f_i(t->b, t->c, t->d) + s[i + 0] + g_t[48]), 6);
	t->d = t->a + b_c((t->d + f_i(t->a, t->b, t->c) + s[i + 7] + g_t[49]), 10);
	t->c = t->d + b_c((t->c + f_i(t->d, t->a, t->b) + s[i + 14] + g_t[50]), 15);
	t->b = t->c + b_c((t->b + f_i(t->c, t->d, t->a) + s[i + 5] + g_t[51]), 21);
	t->a = t->b + b_c((t->a + f_i(t->b, t->c, t->d) + s[i + 12] + g_t[52]), 6);
	t->d = t->a + b_c((t->d + f_i(t->a, t->b, t->c) + s[i + 3] + g_t[53]), 10);
	t->c = t->d + b_c((t->c + f_i(t->d, t->a, t->b) + s[i + 10] + g_t[54]), 15);
	t->b = t->c + b_c((t->b + f_i(t->c, t->d, t->a) + s[i + 1] + g_t[55]), 21);
	t->a = t->b + b_c((t->a + f_i(t->b, t->c, t->d) + s[i + 8] + g_t[56]), 6);
	t->d = t->a + b_c((t->d + f_i(t->a, t->b, t->c) + s[i + 15] + g_t[57]), 10);
	t->c = t->d + b_c((t->c + f_i(t->d, t->a, t->b) + s[i + 6] + g_t[58]), 15);
	t->b = t->c + b_c((t->b + f_i(t->c, t->d, t->a) + s[i + 13] + g_t[59]), 21);
	t->a = t->b + b_c((t->a + f_i(t->b, t->c, t->d) + s[i + 4] + g_t[60]), 6);
	t->d = t->a + b_c((t->d + f_i(t->a, t->b, t->c) + s[i + 11] + g_t[61]), 10);
	t->c = t->d + b_c((t->c + f_i(t->d, t->a, t->b) + s[i + 2] + g_t[62]), 15);
	t->b = t->c + b_c((t->b + f_i(t->c, t->d, t->a) + s[i + 9] + g_t[63]), 21);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function_md5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:29:41 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 13:42:14 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int			f_f(unsigned int x, unsigned int y, unsigned int z)
{
	return (((x & y) | ((~x) & z)));
}

unsigned int			f_g(unsigned int x, unsigned int y, unsigned int z)
{
	return ((x & z) | (y & (~z)));
}

unsigned int			f_h(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int			f_i(unsigned int x, unsigned int y, unsigned int z)
{
	return (y ^ (x | (~z)));
}

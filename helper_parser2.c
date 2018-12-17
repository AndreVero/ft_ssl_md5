/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parser2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 14:42:13 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 15:43:43 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			print_flag(int cript, char *tmp)
{
	if (cript == 1)
		ft_putstr("MD5 (");
	else
		(cript == 2) ? (ft_putstr("SHA256 (")) : (ft_putstr("SHA512 ("));
	ft_putstr(tmp);
	ft_putstr(") = ");
}

void			print_flag_1(int cript, char *tmp)
{
	if (cript == 1)
		ft_putstr("MD5 (\"");
	else
		(cript == 2) ? (ft_putstr("SHA256 (\"")) : (ft_putstr("SHA512 (\""));
	ft_putstr(tmp);
	ft_putstr("\") = ");
}

void			init_function(void (**f)(t_alg *alg))
{
	f[1] = &hash_md5;
	f[2] = &hash_sha256;
	f[3] = &hash_sha512;
}

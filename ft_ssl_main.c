/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:28:27 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 16:20:53 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		init_alg(t_alg *alg, unsigned char *s)
{
	alg->cript = 0;
	alg->r = 0;
	alg->p = 0;
	alg->q = 0;
	alg->std = 0;
	alg->str = s;
}

int			main(int argc, char **argv)
{
	t_alg	*alg;

	alg = (t_alg *)malloc(sizeof(t_alg));
	if (argc >= 2)
	{
		init_alg(alg, (unsigned char *)argv[1]);
		if (parse(alg, argv, argc))
			ft_printf("ft_ssl: Error: \"%s\" is an invalid command.\n\n\
Standard commands:\n\n\
Message Digest commands: md5 sha256 sha512\n\n\
Cipher commands:\n\n", argv[1]);
		free(alg);
	}
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n\
-p, echo STDIN to STDOUT and append the checksum to STDOUT\n\
-q, quiet mode\n\
-r, reverse the format of the output.\n\
-s, print the sum of the given string\n");
}

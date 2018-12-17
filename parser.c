/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 13:28:20 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 20:16:25 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int				equal(const char *s1, const char *s2)
{
	unsigned char		*p2;
	unsigned char		*p1;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 != '\0' || *p2 != '\0')
	{
		if (*p1 > *p2)
			return (*p1 - *p2);
		if (*p2 > *p1)
			return (-1 * (*p2 - *p1));
		p1++;
		p2++;
	}
	return (0);
}

unsigned char			*read_from_fd(int fd)
{
	unsigned char		*res;
	unsigned char		buf[BUF_SIZE + 1];
	int					l;

	res = NULL;
	while (read(fd, buf, BUF_SIZE) > 0)
	{
		if (res == NULL)
		{
			res = (unsigned char *)malloc(sizeof(unsigned char) * 2);
			l = 2;
			res[0] = buf[0];
		}
		else
		{
			res = add_one_char(res, buf[0], l);
			l++;
		}
	}
	return (res);
}

int						check_alg(char *str, t_alg *alg)
{
	if (alg->cript != 0)
		return (0);
	if (!equal(str, "md5"))
	{
		alg->cript = MD5;
		return (0);
	}
	if (!equal(str, "sha256"))
	{
		alg->cript = SHA256;
		return (0);
	}
	if (!equal(str, "sha512"))
	{
		alg->cript = SHA512;
		return (0);
	}
	return (1);
}

static int				check_flag(char **argv, t_alg *alg, int i, int argc)
{
	if (!equal(argv[i], "-p"))
	{
		alg->p = 1;
		print_stdin(alg);
		return (1);
	}
	if (!equal(argv[i], "-r"))
		return (alg->r = 1);
	if (!equal(argv[i], "-q"))
		return (alg->q = 1);
	if (!equal(argv[i], "-s"))
	{
		if (i + 1 == argc)
		{
			alg->std = 1;
			return (ft_printf("String expect (bad using \"-s\")\n") * 0 + 1);
		}
		print_alg_for_s(alg, (unsigned char*)argv[i + 1]);
		return (2);
	}
	return (0);
}

int						parse(t_alg *alg, char **argv, int argc)
{
	int					i;
	int					j;
	int					files;

	files = 0;
	init_function(g_func);
	if (check_alg(argv[1], alg))
		return (1);
	i = 1;
	j = 0;
	if (argc == 2)
		print_stdin(alg);
	while (++i < argc)
	{
		if (!(j = check_flag(argv, alg, i, argc)))
		{
			read_all_like_file(i, argv, argc, alg);
			files++;
			break ;
		}
		(j == 2) ? (i++) : (0);
	}
	if (alg->std == 0 && files == 0)
		print_stdin(alg);
	return (0);
}

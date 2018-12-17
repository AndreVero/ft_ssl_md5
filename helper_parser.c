/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:17:28 by averemiy          #+#    #+#             */
/*   Updated: 2018/09/06 15:04:04 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void				print_stdin(t_alg *alg)
{
	unsigned char	*tmp;

	tmp = read_from_fd(0);
	alg->str = tmp;
	if (alg->p == 1)
		ft_printf("%s", tmp);
	g_func[alg->cript](alg);
	alg->std = 1;
	if (alg->r)
		ft_printf("\n");
	free(tmp);
}

int					print_alg(t_alg *alg, int fd, char *str)
{
	unsigned char	*tmp;

	tmp = read_from_fd(fd);
	alg->str = tmp;
	if (!alg->r && !alg->q)
	{
		if (alg->cript == 1)
			print_flag(1, str);
		else
			(alg->cript == 2) ? (print_flag(2, str)) : (print_flag(3, str));
	}
	g_func[alg->cript](alg);
	if (alg->r && !alg->q)
		ft_printf(" %s\n", str);
	else if (alg->r)
		ft_printf("\n");
	free(tmp);
	return (0);
}

void				print_alg_for_s(t_alg *alg, unsigned char *tmp)
{
	alg->str = tmp;
	if (!alg->r && !alg->q)
	{
		if (alg->cript == 1)
			print_flag_1(1, (char *)tmp);
		else
			(alg->cript == 2) ? (print_flag_1(2, (char *)tmp))
				: (print_flag_1(3, (char *)tmp));
	}
	g_func[alg->cript](alg);
	if (alg->r && !alg->q)
		ft_printf(" \"%s\"\n", tmp);
	else if (alg->r)
		ft_printf("\n");
	alg->std = 1;
}

void				read_all_like_file(int i, char **argv, int argc, t_alg *alg)
{
	int				fd;

	fd = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDWR);
		if (fd > 0)
			print_alg(alg, fd, argv[i]);
		else
			ft_printf("ft_ssl: %s - no such file or directory\n", argv[i]);
		i++;
	}
}

unsigned char		*add_one_char(unsigned char *tmp, unsigned char c, \
		int l)
{
	unsigned char	*test;
	int				j;
	unsigned char	*tmp1;
	unsigned char	*test1;

	tmp1 = tmp;
	j = -1;
	test = (unsigned char *)malloc(sizeof(unsigned char) * l + 1);
	test1 = test;
	while (++j < l - 1)
		test[j] = tmp[j];
	free(tmp1);
	test[j] = c;
	test[j + 1] = '\0';
	return (test1);
}

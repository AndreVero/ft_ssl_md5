/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:21:10 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/27 15:42:20 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "md5.h"
# include "sha256.h"
# include "sha512.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "ft_printf/print.h"

# define MD5 1
# define SHA256 2
# define SHA512 3
# define BUF_SIZE 1

void				(*g_func[3])(t_alg *alg);
void				print_stdin(t_alg *alg);
int					parse(t_alg *alg, char **argv, int argc);
unsigned char		*read_from_fd(int fd);
void				read_all_like_file(int i,\
		char **argv, int argc, t_alg *alg);
void				print_alg_for_s(t_alg *alg, unsigned char *tmp);
unsigned char		*add_one_char(unsigned char *tmp, unsigned char c, \
				int l);
void				print_flag(int cript, char *tmp);
void				print_flag_1(int cript, char *tmp);
void				init_function(void (**f)(t_alg *alg));

#endif

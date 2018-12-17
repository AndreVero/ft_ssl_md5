/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:41:16 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:09:19 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static	char	*parser(char *s, int i)
{
	char		*res;
	int			j;
	int			k;

	res = NULL;
	j = i;
	k = 1;
	while (s[i] != '\0' && s[i] != 's' && s[i] != 'S' && s[i] != 'p'
			&& s[i] != 'd' && s[i] != 'D' && s[i] != 'i' && s[i] != 'o'
			&& s[i] != 'O' && s[i] != 'u' && s[i] != 'U' && s[i] != 'x'
			&& s[i] != 'X' && s[i] != 'c' && s[i] != 'C' && s[i] != '%')
	{
		i++;
		k++;
	}
	if (s[i] == '\0')
		res = ft_strsub(s, j, j + 1);
	else
		res = ft_strsub(s, j, k);
	return (res);
}

int				find_size_spec(t_spe **t, char *s, int i)
{
	int			res;

	res = 0;
	if (s[i] == '.')
	{
		(*t)->pointer = 1;
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			res = (res * 10) + (s[i] - '0');
			i++;
		}
		res++;
	}
	return (res);
}

char			*find_size_modifire(char *s, int i)
{
	char		*res;
	char		*tmp;

	res = NULL;
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (ft_strlen(s) > 1)
	{
		tmp = ft_strsub(s, i, i + 2);
		if (!(ft_strcmp("ll", tmp))
				|| !(ft_strcmp("hh", tmp)))
		{
			free(tmp);
			return (ft_strsub(s, i, i + 2));
		}
		free(tmp);
	}
	if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z')
		res = ft_strsub(s, i, i + 1);
	else
		res = ft_strnew(1);
	return (res);
}

t_spe			*create_t_spe(char *s)
{
	t_spe		*t;
	int			i;

	i = 0;
	t = (t_spe*)malloc(sizeof(t_spe));
	t->size = 0;
	t->size_mdf = NULL;
	t->plus = 0;
	t->minus = 0;
	t->zero = 0;
	t->space = 0;
	t->hash = 0;
	t->for_plus = 0;
	t->pointer = 0;
	i = find_flags(s, &t);
	while (s[i] >= '0' && s[i] <= '9')
	{
		t->size = (10 * t->size) + (s[i] - '0');
		i++;
	}
	t->size_spec = find_size_spec(&t, s, i);
	t->size_mdf = find_size_modifire(s, i);
	t->symb = s[ft_strlen(s) - 1];
	t->for_plus = ft_strlen(s);
	return (t);
}

t_spe			*make_elem(char *str, int i)
{
	char		*after_pars;
	t_spe		*res;

	after_pars = parser(str, i + 1);
	if (!after_pars)
	{
		res = (t_spe *)malloc(sizeof(t_spe));
		res->for_plus = 0;
		res->size_mdf = ft_strdup("0");
		res->symb = '0';
	}
	else
	{
		if (check_valid(after_pars))
			res = not_valid(after_pars);
		else
			res = create_t_spe(after_pars);
		free(after_pars);
	}
	return (res);
}

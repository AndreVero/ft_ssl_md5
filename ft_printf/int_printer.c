/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:15:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 14:45:29 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

char				*m(char *our, int size)
{
	char			*res;
	int				i;
	char			*result;

	i = 0;
	res = NULL;
	if (our == NULL)
		our = ft_strnew(1);
	if (size > 0)
		res = ft_strnew(size);
	else
		res = ft_strnew(1);
	while (i < size - 1)
	{
		res[i] = '0';
		i++;
	}
	res[i] = '\0';
	result = ft_strjoin(our, res);
	free(res);
	free(our);
	return (result);
}

static char			*concat_right_str(char ch, t_spe **t, long long int c)
{
	char			*s1;
	char			*s2;
	char			*s3;
	char			*s4;

	s2 = ft_strnew(1);
	*s2 = ch;
	s4 = ft_itoal(c);
	s1 = m(s2, (*t)->size_spec - ft_strlen(s4));
	s3 = ft_strjoin(s1, s4);
	free(s4);
	free(s1);
	return (s3);
}

static	char		*another_way(t_spe **t, long long int c)
{
	char			*s;

	s = NULL;
	if (c < 0)
	{
		c = -c;
		s = concat_right_str('-', t, c);
	}
	else if (c >= 0 && (*t)->plus)
		s = concat_right_str('+', t, c);
	else if (c >= 0 && (*t)->space)
		s = concat_right_str(' ', t, c);
	else
		s = concat_right_str('\0', t, c);
	return (s);
}

static	int			find_arr(t_spe **t, long long int c)
{
	if (c < 0 && (*t)->zero && (*t)->size_spec <= 0)
	{
		ft_putchar('-');
		return (printall(make_int_minus(t, c), t, (*t)->size) + 1);
	}
	else if (c >= 0 && (*t)->plus && (*t)->zero && (*t)->size_spec <= 0)
	{
		ft_putchar('+');
		return (printall(make_int_plus(t, c), t, (*t)->size) + 1);
	}
	else if (c >= 0 && (*t)->space && (*t)->zero && (*t)->size_spec <= 0)
	{
		ft_putchar(' ');
		return (printall(make_int_space(t, c), t, (*t)->size) + 1);
	}
	else if (c == 0 && (*t)->pointer && (*t)->size > 0)
		return (printall(m(ft_strdup(" "), (*t)->size_spec), t, (*t)->size));
	else if (c == 0 && (*t)->pointer && (*t)->size <= 0)
		return (printall(m(ft_strdup(""), (*t)->size_spec), t, (*t)->size));
	return (printall(another_way(t, c), t, (*t)->size));
}

int					int_printer(t_spe **t, long long int count)
{
	if (!ft_strcmp((*t)->size_mdf, "h") && (*t)->symb == 'd')
		return (find_arr(t, (short int)count));
	if (!ft_strcmp((*t)->size_mdf, "hh") && ((*t)->symb == 'd' ||
				(*t)->symb == 'i'))
		return (find_arr(t, (char)count));
	if (!ft_strcmp((*t)->size_mdf, "hh") && (*t)->symb == 'D')
		return (find_arr(t, (unsigned short)count));
	if (((*t)->symb == 'd' && !ft_strcmp((*t)->size_mdf, "l")) ||
			((*t)->symb == 'D') ||
			((*t)->symb == 'i' && !(ft_strcmp((*t)->size_mdf, "l"))))
		return (find_arr(t, (long int)count));
	if (((*t)->symb == 'd' && !ft_strcmp((*t)->size_mdf, "ll")) ||
			((*t)->symb == 'D' && !ft_strcmp((*t)->size_mdf, "l")) ||
			(!ft_strcmp((*t)->size_mdf, "z")) ||
			(!ft_strcmp((*t)->size_mdf, "j")) ||
			((*t)->symb == 'i' && !ft_strcmp((*t)->size_mdf, "ll")))
		return (find_arr(t, (long long int)count));
	if ((*t)->symb == 'd' || (*t)->symb == 'i')
		return (find_arr(t, (int)count));
	else
		return (find_arr(t, (long long int)count));
}

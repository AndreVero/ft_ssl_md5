/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 00:43:18 by averemiy          #+#    #+#             */
/*   Updated: 2018/05/06 15:21:00 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int					check_valid(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= '0' && *str <= '9') || (*str == ' ') || (*str == '#')
				|| (*str == '-') || (*str == '+') || (*str == 'l') ||
				(*str == 'l') || (*str == 'h') || (*str == 'j') || (*str == 'z')
				|| (*str == 'd') || (*str == 'D') || (*str == 's') ||
				(*str == 'S') || (*str == 'p') || (*str == 'i') ||
				(*str == 'o') || (*str == 'O') || (*str == 'u') ||
				(*str == 'U') || (*str == 'x') || (*str == 'X')
				|| (*str == 'c') || (*str == 'C') ||
				(*str == '%') || (*str == '.'))
			str++;
		else
			return (1);
	}
	return (0);
}

int					find_length(char *str)
{
	int				i;

	i = 0;
	while (*str != '\0' && (*str == ' ' ||
				(*str >= '0' && *str <= '9') || (*str == '#')
				|| (*str == '+') || (*str == '-') || (*str == '.')))
	{
		i++;
		str++;
	}
	return (i);
}

t_spe				*not_valid(char *s)
{
	t_spe			*t;
	int				i;

	i = 0;
	t = (t_spe*)malloc(sizeof(t_spe));
	t->size = 0;
	t->size_mdf = NULL;
	t->plus = 0;
	t->minus = 0;
	t->space = 0;
	t->hash = 0;
	t->for_plus = 0;
	t->pointer = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		t->size = (10 * t->size) + (s[i] - '0');
		i++;
	}
	t->size_spec = find_size_spec(&t, s, i);
	t->size_mdf = find_size_modifire(s, i);
	t->symb = '/';
	t->for_plus = find_length(s);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:55:55 by psoares-          #+#    #+#             */
/*   Updated: 2023/05/12 15:24:51 by psoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i] && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long int	result;
	long int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	is_digit(char *s)
{
	while (*s)
	{
		if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	return (1);
}

int	is_double(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			s++;
			break ;
		}
		else if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	while (*s)
	{
		if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	return (1);
}

int	verify_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (i == 1 && argv[1][0] != 'm' && argv[1][0] != 'j' && \
		argv[1][0] != 'b')
			return (0);
		else if (i == 2 && !is_digit(argv[i]))
			return (0);
		else if (i == 2 && is_digit(argv[i]) && ft_atoi(argv[i]) <= 0)
			return (0);
		else if (i > 2 && !is_double(argv[i]))
			return (0);
	}
	return (1);
}

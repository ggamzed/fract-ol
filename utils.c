/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:18:16 by gdemirci          #+#    #+#             */
/*   Updated: 2025/04/21 21:18:17 by gdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	is_digit(char *str)
{
	if ('0' <= *str && *str <= '9')
		return (1);
	return (0);
}

double	parse_int(char **str)
{
	double	result;

	result = 0.0;
	while (is_digit(*str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	parse_fractional(char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		(*str)++;
		if (!is_digit(*str))
			check_err();
		while (is_digit(*str))
		{
			fraction += (**str - '0') / divisor;
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction);
}

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '\0')
		check_err();
	result = parse_int(&str);
	fraction = parse_fractional(&str);
	if (*str != '\0')
		check_err();
	return (sign * (result + fraction));
}

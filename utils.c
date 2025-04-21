#include <stdlib.h>
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	ft_skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	is_neg = 1;
	nb = 0;
	div = 0.1;
	i = ft_skip(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
		nb = (nb * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb += (str[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		write(1, "Invalid value\n", 14);
	return (nb * is_neg);
}
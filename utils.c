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

double parse_integer_part(const char **str)
{
    double result;

	result = 0.0;
    while (**str >= '0' && **str <= '9')
    {
        result = result * 10.0 + (**str - '0');
        (*str)++;
    }
    return result;
}

double parse_fractional_part(const char **str)
{
    double fraction;
    double divisor;
    
	fraction = 0.0;
	divisor = 10.0;
    if (**str == '.')
    {
        (*str)++;
        while (**str >= '0' && **str <= '9')
        {
            fraction += (**str - '0') / divisor;
            divisor *= 10.0;
            (*str)++;
        }
    }
    return fraction;
}


double ft_atod(const char *str)
{
    double result;
    double fraction;
    int sign;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-' )
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    if (*str == '\0')
        exit(EXIT_FAILURE);
    result = parse_integer_part(&str);
    if (*str == '.' && (*(str + 1) < '0' || *(str + 1) > '9'))
        exit(EXIT_FAILURE);
    fraction = parse_fractional_part(&str);
    if (*str != '\0')
        exit(EXIT_FAILURE);
    return (sign * (result + fraction));
}
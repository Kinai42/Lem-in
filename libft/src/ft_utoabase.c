#include "libft.h"

char				*ft_utoabase(unsigned int n, unsigned int b)
{
	char			*str;
	unsigned int	t;
	unsigned int	i;

	i = 2;
	t = 1;
	while (n / t >= b)
	{
		++i;
		t *= b;
	}
	str = (char*)ft_memalloc(sizeof(char) * i);
	i = 0;
	while (t)
	{
		str[i++] = "0123456789abcdef"[n / t % b];
		t /= b;
	}
	str[i] = '\0';
	return (str);
}

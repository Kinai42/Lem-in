
#include "libft.h"

unsigned int	ft_strcount(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}

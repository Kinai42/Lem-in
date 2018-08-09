
#include "libft.h"

#include <stdlib.h>

void	ft_parrprem(void **tab, void *elem)
{
	unsigned int	arr_len;

	arr_len = ft_parrlen(tab);
	while (*tab != elem)
	{
		++tab;
		--arr_len;
	}
	while (--arr_len)
	{
		tab[0] = tab[1];
		++tab;
	}
	tab[0] = 0;
}

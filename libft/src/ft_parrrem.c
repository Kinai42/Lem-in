
#include "libft.h"

void	ft_parrrem(void **tab)
{
	while (*tab)
	{
		*tab = tab[1];
		++tab;
	}
}

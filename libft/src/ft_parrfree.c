
#include "libft.h"

void	ft_parrfree(void **array)
{
	void	**beg;

	beg = array;
	while (*array)
		free(*array++);
	free(beg);
}

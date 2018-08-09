
#include "libft.h"

void	ft_parrelmfree(void **array)
{
	void	**beg;

	beg = array;
	while (*array)
		free(**(void***)array++);
}

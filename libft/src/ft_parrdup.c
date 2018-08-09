
#include "libft.h"

void	**ft_parrdup(void **array)
{
	void	**n_arr;

	n_arr = ft_parrnew();
	while (*array)
		ft_parrpush(&n_arr, *array++);
	return (n_arr);
}

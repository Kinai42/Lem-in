
#include "libft.h"

void	**ft_parrjoin(void **a1, void **a2)
{
	void	**na;

	na = ft_parrnew();
	while (*a1)
		ft_parrpush(&na, *a1++);
	while (*a2)
		ft_parrpush(&na, *a2++);
	return (na);
}

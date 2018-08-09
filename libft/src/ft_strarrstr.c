#include "libft.h"

int		ft_strarrstr(char **array, char *str)
{
	int		i;

	i = 0;
	while (array[i] && ft_strcmp(array[i], str))
		++i;
	return (array[i]) ? i : -1;
}

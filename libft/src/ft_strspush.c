#include "libft.h"

void	ft_strspush(char **str, char *push)
{
	char			*n_str;
	unsigned int	strlen;
	unsigned int	pushlen;

	strlen = ft_strlen(*str);
	pushlen = ft_strlen(push);
	n_str = (strlen / ALLOC_STRING == (strlen + pushlen) / ALLOC_STRING
		&& strlen) ? *str : (char*)ft_memalloc(sizeof(char) * (strlen
        + pushlen + ALLOC_STRING - (strlen + pushlen) % ALLOC_STRING + 1));
	n_str[strlen + pushlen] = '\0';
	while (pushlen--)
		n_str[strlen + pushlen] = push[pushlen];
	if (n_str == *str)
		return ;
	while (strlen--)
		n_str[strlen] = (*str)[strlen];
	free(*str);
	*str = n_str;
}

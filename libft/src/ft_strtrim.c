/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:33:22 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/21 16:33:25 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int		f_space(const char *s)
{
	int i;

	i = 0;
	while (is_space(s[i]) == 1)
		i++;
	return (i);
}

static int		l_space(const char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (is_space(s[i]) == 0)
			return ((ft_strlen(s) - 1) - i);
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		p;
	char	*k;

	if (!s)
		return (NULL);
	i = f_space(s);
	p = 0;
	k = ft_strnew((ft_strlen(s) - (i + l_space(s))));
	if (k == NULL)
		return (NULL);
	while ((unsigned long)i != (ft_strlen(s) - l_space(s)))
	{
		k[p] = s[i];
		p++;
		i++;
	}
	return (k);
}

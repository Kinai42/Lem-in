/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:20:25 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:20:30 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **tab)
{
	char	**tabcpy;
	int	count;
	int	i;
	
	count = ft_counttab(tab);
	i = -1;
	if(!(tabcpy = malloc(sizeof(char *) * count + 1)))
		return(0);
	tab[count] = NULL;
	while(++i < count - 1)
		tabcpy[i] = ft_strdup(tab[i]);
	return(tabcpy);
}

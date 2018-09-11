/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:16:14 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/11 12:17:57 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_free_lemin(t_lemin lemin)
{
	int	i;

	i = -1;
	while (lemin.box[++i])
	{
		free(lemin.box[i]->name);
		if (lemin.box[i]->pipes)
			free((void **)lemin.box[i]->pipes);
		free(lemin.box[i]);
	}
	free((void **)lemin.box);
	i = -1;
	if (lemin.paths)
	{
		while (lemin.paths[++i])
			free(lemin.paths[i]);
		free(lemin.paths);
	}
}

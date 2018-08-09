/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:47 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:00:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_box		**convert_path(t_lemin *lemin, char **path)
{
	t_box	**conv;
	int		i;

	conv = (t_box**)ft_parrnew();
	while (*path)
	{
		i = 0;
		while (ft_strcmp(lemin->box[i]->name, *path))
			i++;
		ft_parrpush((void***)&conv, lemin->box[i]);
		path++;
	}
	return (conv);
}

char		**skip_coms(char **lines)
{
	while (*lines && **lines == '#' && *(*lines + 1) != '#')
		lines++;
	return (lines);
}

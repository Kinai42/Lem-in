/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:16 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/09 05:35:12 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	t_lemin		lemin;

	lemin.start = 0;
	lemin.end = 0;
	lemin.outants = 0;
	lemin.box = (t_box**)ft_parrnew();
	lemin.output = ft_strnew();
	if (get_anthill(&lemin))
		solve(&lemin);
	return (0);
}

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

t_box		*ft_mallocbox(char **split)
{
	t_box *box;

	box = (t_box*)(ft_memalloc(sizeof(t_box)));
	box->name = ft_strdup(split[0]);
	box->x = ft_atoi(split[1]);
	box->y = ft_atoi(split[2]);
	box->pipes = (t_box**)ft_parrnew();
	return (box);
}

void		ft_free(t_box *box, char **split)
{
	free(box->name);
	ft_parrfree((void **)box->pipes);
	free(box);
	ft_parrfree((void **)split);
}

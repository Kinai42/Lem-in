/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:16 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:00:20 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				main(void)
{
	t_lemin		lemin;

	lemin.start = 0;
	lemin.end = 0;
    lemin.outAnts = 0;
	lemin.box = (t_box**)ft_parrnew();
	lemin.output = ft_strnew(0);
	if (get_anthill(&lemin))
		solve(&lemin);
	return (0);
}

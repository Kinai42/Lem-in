/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:01:32 by dbauduin          #+#    #+#             */
/*   Updated: 2018/09/11 11:55:38 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct		s_box
{
	char			status;
	char			*name;
	int				x;
	int				y;
	int				ant;
	struct s_box	**pipes;
}					t_box;

typedef struct		s_lemin
{
	t_box			**box;
	t_box			*start;
	t_box			*end;
	int				nbants;
	int				outants;
	struct s_box	***paths;
	int				nbpaths;
	int				min;
	char			*output;
}					t_lemin;

char				get_anthill(t_lemin *lemin);
void				solve(t_lemin *lemin);
void				run(t_lemin *lemin);
t_box				**convert_path(t_lemin *lemin, char **path);
char				**skip_coms(char **lines);
t_box				*ft_mallocbox(char **split);
void				ft_free(t_box *box, char **split);
void				ft_free_lemin(t_lemin lemin);

#endif


#ifndef LEMIN_H
# define LEMIN_H

#include "libft.h"


typedef struct      s_box
{
	char			status;
	char			*name;
	int				x;
	int				y;
	int				ant;


	struct s_box	**pipes;
}                   t_box;

typedef struct      s_lemin
{
    t_box           **box;

	t_box			*start;
    t_box           *end;

	int				nbAnts;
    int             outAnts;

	struct s_box	***paths;
    int             nbPaths;
    int             min;

	char			*output;

}                   t_lemin;


char				get_anthill(t_lemin *lemin);
void				solve(t_lemin *lemin);
void				run(t_lemin *lemin);
t_box				**convert_path(t_lemin *lemin, char **path);
char				**skip_coms(char **lines);

#endif

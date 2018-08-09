
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

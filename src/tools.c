
#include "lemin.h"

#include "libft.h"

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

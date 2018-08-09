/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:24 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/09 03:00:38 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		**get_path(t_lemin *lemin, t_box *box, int len, char ***path)
{
    int		i;
    char	**tmp;

    i = 0;
    while (len && box->pipes[i])
    {
        if (box->pipes[i] == lemin->end)
        {
            ft_parrpush((void***)path, box->pipes[i]->name);
            return (*path);
        }
        if (box->pipes[i]->status == 1)
        {
            ft_parrpush((void***)path, box->pipes[i]->name);
            if ((tmp = get_path(lemin, box->pipes[i], len - 1, path)))
                return (tmp);
            (*path)[ft_parrlen((void**)(*path)) - 1] = 0;
        }
        i++;
    }
    return (0);
}

static void		init_path(t_lemin *lemin, char **path)
{
    int		i;

    i = 0;
    while (lemin->box[i])
    {
        if (lemin->box[i] != lemin->start && lemin->box[i] != lemin->end &&
                (ft_strarrstr(path, lemin->box[i]->name)) != -1)
        {
            lemin->box[i]->status = 0;
            lemin->box[i]->ant = 0;
        }
        else if (lemin->box[i] == lemin->start)
            lemin->box[i]->ant = 1;
        else if (lemin->box[i] == lemin->end)
            lemin->box[i]->ant = 0;
        i++;
    }
}

void			solve(t_lemin *lemin)
{
    char		**path;
    int			i;

    i = 1;
    lemin->paths = (t_box***)ft_parrnew();
    while (lemin->nbPaths && lemin->box[i])
    {
        path = (char**)ft_parrnew();
        ft_parrpush((void***)&path, lemin->start->name);
        /*On recherche les chemins valides ordre croissant*/
        /*get_path recherche recursive*/
        if (get_path(lemin, lemin->start, i, &path))
        {
            ft_parrpush((void***)&lemin->paths, convert_path(lemin, path));
            /*On bloque le path pour ne pas revenir une une box deja utilise status = 0*/
            init_path(lemin, path);
            lemin->nbPaths--;
        }
        else
            i++;
        free(path);
    }
    if (!(lemin->nbPaths = ft_parrlen((void**)lemin->paths)))
        ft_print(2, "ERROR\n");
    else
        run(lemin);
}

static void		move_ants(t_lemin *lemin, t_box *origin, t_box *dst, int len)
{
    if (origin == lemin->start && (lemin->nbAnts - lemin->start->ant) >= (len - lemin->min) && lemin->start->ant <= lemin->nbAnts)
        dst->ant = origin->ant++;
    else if (origin != lemin->start)
    {
        dst->ant = origin->ant;
        origin->ant = 0;
    }
    else
        return ;
    ft_print(1, "L%d-%s ", dst->ant, dst->name);
    if (dst == lemin->end)
        lemin->outAnts++;
}

void			run(t_lemin *lemin)
{
    int		i;
    int		box;

    lemin->min = ft_parrlen((void**)lemin->paths[0]);
    ft_putstr(lemin->output);
    free(lemin->output);
    while (lemin->outAnts != lemin->nbAnts)
    {
        i = 0;
        while (lemin->paths[i])
        {
            box = (int)ft_parrlen((void**)lemin->paths[i]) - 1;
            int len = box + 1;
            while (box)
            {
                if (lemin->paths[i][box - 1]->ant) 
                    move_ants(lemin, lemin->paths[i][box - 1], lemin->paths[i][box], len);
                box--;
            }
            i++;
        }
        ft_putchar('\n');
    }
}

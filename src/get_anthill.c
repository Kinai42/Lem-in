/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:07 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/13 15:37:07 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		check(t_lemin *lemin, char **lines, long offset)
{
    int		i;

    if (!lemin->start || !lemin->end)
    {
        ft_parrfree((void**)lines);
        return (0);
    }
    lemin->nbPaths = ft_parrlen((void**)lemin->start->pipes);
    if (ft_parrlen((void**)lemin->end->pipes) < lemin->nbPaths)
        lemin->nbPaths = ft_parrlen((void**)lemin->end->pipes);
    i = 0;
    if (lemin->nbPaths)
    {
        while (offset--)
        {
            ft_strpush(&lines[i], '\n');
            ft_strspush(&lemin->output, lines[i++]);
        }
        ft_strpush(&lemin->output, '\n');
    }
    ft_parrfree((void**)lines);
    return (lemin->nbPaths) ? 1 : 0;
}

static char		**get_pipe(t_lemin *lemin, char **line)
{
    char	**split;
    int		i;
    int		j;

    line = skip_coms(line);
    while (*line)
    {
        if (ft_strcount(*line, '-') != 1 || ft_parrlen((void**)(split = ft_strsplit(*line, '-'))) != 2 || !ft_strcmp(split[0], split[1]))
            break ;
        i = 0;
        while (lemin->box[i] && ft_strcmp(lemin->box[i]->name, split[0]))
            i++;
        j = 0;
        while (lemin->box[j] && ft_strcmp(lemin->box[j]->name, split[1]))
            j++;
        ft_parrfree((void**)split);
        if (!lemin->box[i] || !lemin->box[j])
            break ;
        ft_parrpush((void***)&lemin->box[i]->pipes, lemin->box[j]);
        ft_parrpush((void***)&lemin->box[j]->pipes, lemin->box[i]);
        line = skip_coms(++line);
    }
    return (line);
}

static char		add_box(t_lemin *lemin, t_box *box, char spe)
{
    if ((spe == 1 && lemin->start) || (spe == 2 && lemin->end))
        return (0);
    ft_parrpush((void***)&lemin->box, box);
    lemin->start = spe == 1 ? box : lemin->start;
    lemin->end = spe == 2 ? box : lemin->end;
    box->status = spe ? 2 : 1;
    return (1);
}

static char		**get_box(t_lemin *lemin, char **line)
{
    t_box		*box;
    char		**split;
    char		spe;

    line = skip_coms(line);
    while (*line)
    {
        spe = 0;
        if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end")) 
            spe = 1 + !ft_strcmp(*line++, "##end");
        if (!*line || ft_strcount(*line, ' ') != 2 || **line == 'L' ||
                ft_parrlen((void**)(split = ft_strsplit(*line, ' '))) != 3) 
            break ;
        box = ft_mallocbox(split);
        if (ft_strchr(split[0], '-') || split[1][ft_intlen(box->x)] ||
                split[2][ft_intlen(box->y)] || !add_box(lemin, box, spe))
        {
            ft_free(box, split);
            break ;
        }
        ft_parrfree((void**)split);
        line = skip_coms(++line);
    }
    return (get_pipe(lemin, spe ? line - 1 : line));
}

char			get_anthill(t_lemin *lemin)
{
    char		*line;
    char		**lines;
    char		**offset;
    int			i;

    lines = (char**)ft_parrnew();
    while ((line = ft_gnl(0)))
        ft_parrpush((void***)&lines, line);
    i = -1;
    while (lines[++i] && *lines[i] == '#' && *(lines[i] + 1) != '#');
    if (lines[i] && ((lemin->nbAnts = ft_atoi(lines[i])) > 0) && !lines[i][ft_intlen(lemin->nbAnts)])
    {
        offset = get_box(lemin, &lines[++i]);
        if (check(lemin, lines, offset - lines))
            return (1);
    }
    else
        ft_parrfree((void**)lines);
    ft_print(2, "ERROR\n");
    return (0);
}

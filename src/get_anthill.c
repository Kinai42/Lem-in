/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:00:07 by dbauduin          #+#    #+#             */
/*   Updated: 2018/08/11 06:30:01 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		check(t_lemin *lemin, char **lines, long offset)
{
	int		i;

	if (!lemin->start || !lemin->end)
		return (0);
    /*Nombre maximum de chemin possible*/
	lemin->nbPaths = ft_parrlen((void**)lemin->start->pipes);
	if (ft_parrlen((void**)lemin->end->pipes) < lemin->nbPaths)
		lemin->nbPaths = ft_parrlen((void**)lemin->end->pipes);
	i = 0;
    //printf("[%d]\n", lemin->nbPaths);
    /*Save la partie du texte valide dans output (char*)*/
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

    /*On cherche les tubes valides*/
	line = skip_coms(line);
	while (*line)
	{
		if (ft_strcount(*line, '-') != 1 || ft_parrlen((void**)(split = ft_strsplit(*line, '-'))) != 2 || !ft_strcmp(split[0], split[1]))
			break ;
		i = 0;
        /*On recherche l'index des box presents*/
		while (lemin->box[i] && ft_strcmp(lemin->box[i]->name, split[0]))
			i++;
		j = 0;
		while (lemin->box[j] && ft_strcmp(lemin->box[j]->name, split[1]))
			j++;
		if (!lemin->box[i] || !lemin->box[j])
			break ;
		ft_parrpush((void***)&lemin->box[i]->pipes, lemin->box[j]);
		ft_parrpush((void***)&lemin->box[j]->pipes, lemin->box[i]);
		ft_parrfree((void**)split);
		line = skip_coms(++line);
	}
	return (line);
}

static char		add_box(t_lemin *lemin, t_box *box, char spe)
{
    /*Verife si start || end existe deja*/
    //printf("SPE =[%d]\n", spe);
	if ((spe == 1 && lemin->start) || (spe == 2 && lemin->end))
		return (0);
    /*On ajoute une boite dans lemin->box/start/end*/
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
    /*On cherche les Box valides*/
	while (*line && !((*line)[ft_intlen(ft_atoi(*line))] == '-'))
	{
    //printf("OK\n");
        spe = 0;
        /*if start || end spe = 1 || 2 */
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end")) 
            spe = 1 + !ft_strcmp(*line++, "##end");
		split = ft_strsplit(*line, ' ');
        /*Verife format 2 ' ' et pas de L*/
		if (!*line || ft_strcount(*line, ' ') != 2 || **line == 'L' || ft_parrlen((void**)(split = ft_strsplit(*line, ' '))) != 3 || ft_strchr(split[0], '-'))
			break ;
		box = (t_box*)ft_memalloc(sizeof(t_box));
		box->name = ft_strdup(split[0]);
        box->x = ft_atoi(split[1]);
        box->y = ft_atoi(split[2]);
		box->pipes = (t_box**)ft_parrnew();
    //printf("Box->name = %s\n", box->name);
        /*Ajoute la box a la liste*/
    //printf("SPLIT[0] = [%s] [%s]\n", split[0], box->name);
    //printf("SPLIT[1] = [%s] [%d] [%c]\n", split[1], box->x, split[1][ft_intlen(box->x)]);
    //printf("SPLIT[2] = [%s] [%d] [%c]\n", split[2], box->y, split[2][ft_intlen(box->y)]);
		if (split[1][ft_intlen(box->x)] || split[2][ft_intlen(box->y)] || !add_box(lemin, box, spe))
			break ;
    //printf("lemin->box = %s\n", lemin->box[ft_parrlen((void**)(lemin->box)) - 1]->name);
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

    /*Recupere les infos dans LINES*/
	lines = (char**)ft_parrnew();
	while ((line = ft_gnl(0)))
		ft_parrpush((void***)&lines, line);
    /*Skip les commentaires*/
	i = -1;
	while (lines[++i] && *lines[i] == '#' && *(lines[i] + 1) != '#');
    /*On doit trouver le nombre de fourmis*/
	if (lines[i] && ((lemin->nbAnts = ft_atoi(lines[i])) > 0) && !lines[i][ft_intlen(lemin->nbAnts)])
	{
    /*printf("ANT = [%d]\n", lemin->nbAnts);*/
	offset = get_box(lemin, &lines[++i]);
    //printf("-OK\n");
    if (check(lemin, lines, offset - lines))
		return (1);
	}
    /*Si aucun chemin valide trouve*/
	ft_print(2, "ERROR\n");
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:28:25 by gfournie          #+#    #+#             */
/*   Updated: 2016/04/30 20:28:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void	newobjvect(char *line, float *v, t_env *env, int t)
{
	while (ISWHITESPACE)
		line++;
	v[0] = ft_fatoi(line);
	while (!(ISWHITESPACE || *line == '\0'))
		line++;
	while (ISWHITESPACE)
		line++;
	v[1] = ft_fatoi(line);
	while (!(ISWHITESPACE || *line == '\0'))
		line++;
	while (ISWHITESPACE)
		line++;
	v[2] = ft_fatoi(line);
	if (t)
	{
		env->maxx = (v[0] > env->maxx) ? v[0] : env->maxx;
		env->maxy = (v[1] > env->maxy) ? v[1] : env->maxy;
		env->maxz = (v[2] > env->maxz) ? v[2] : env->maxz;
		env->minx = (v[0] < env->minx) ? v[0] : env->minx;
		env->miny = (v[1] < env->miny) ? v[1] : env->miny;
		env->minz = (v[2] < env->minz) ? v[2] : env->minz;
	}
}

void	objreaderaux(char *line, t_read *r, t_env *env)
{
	if (line[0] != 'v' && line[0] != 'f')
		return ;
	else if (line[0] == 'v' && line[1] == ' ')
	{
		newobjvect(&line[1], &r->v[r->i], env, 1);
		r->i += 3;
	}
	else if (line[0] == 'v' && line[1] == 'n')
	{
		newobjvect(&line[2], &r->vn[r->j], env, 0);
		r->j += 3;
	}
	else if (line[0] == 'v' && line[1] == 't')
	{
		newobjvect(&line[2], &r->vt[r->k], env, 0);
		r->k += 3;
	}
	else if (line[0] == 'f' && line[1] == ' ')
		newtriangleobj(&line[1], r, &(env->nbtr));
}

float	*objreader(char *name, t_env *env)
{
	int			fd;
	char		*line;
	t_read		r;

	r.v = malloc(sizeof(r.v) * (LIMIT + 1));
	r.r = malloc(sizeof(r.r) * (LIMIT + 1));
	r.vn = malloc(sizeof(r.vn) * (LIMIT + 1));
	r.vt = malloc(sizeof(r.vt) * (LIMIT + 1));
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("pas de .obj");
	line = NULL;
	r.i = 3;
	r.j = 3;
	r.k = 3;
	while (get_next_line(fd, &line) > 0 && (r.i + r.j + r.k) * 3 < LIMIT)
	{
		objreaderaux(line, &r, env);
		ft_strdel(&line);
	}
	if ((r.i + r.j + r.k) * 3 >= LIMIT)
		ft_error("dafuq5546");
	free(r.v);
	free(r.vn);
	free(r.vt);
	return (r.r);
}

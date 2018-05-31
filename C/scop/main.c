/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:43:55 by gfournie          #+#    #+#             */
/*   Updated: 2017/07/26 17:43:57 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"
#include <stdio.h>

int		key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 123)
		env->pos[0] -= 0.03;
	else if (key == 124)
		env->pos[0] += 0.03;
	else if (key == 125)
		env->pos[1] -= 0.03;
	else if (key == 126)
		env->pos[1] += 0.03;
	else if (key == 27)
		env->pos[2] -= 0.03;
	else if (key == 24)
		env->pos[2] += 0.03;
	else if (env->textname != NULL && key == 15)
		env->texte = (env->texte) ? 0 : 1;
	else if (key == 35)
		env->pause = (env->pause) ? 0 : 1;
	return (0);
}

int		expose_hook(t_env *env)
{
	struct timeval	t;
	double			truc;
	static int		trucinit = -1;

	gettimeofday(&t, NULL);
	if (env->texte == 1 && env->textenable < 1)
		env->textenable += 0.01;
	if (env->texte == 0 && env->textenable > 0)
		env->textenable -= 0.01;
	if (trucinit == -1)
		trucinit = t.tv_sec;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	truc = t.tv_sec - trucinit + ((double)t.tv_usec / 1000000.0);
	if (env->pause == 0)
		glUniform1f(glGetUniformLocation(env->shader_programme, "time"), truc);
	glUniform1f(glGetUniformLocation(env->shader_programme, "texte"),
		env->textenable);
	glUniform3fv(glGetUniformLocation(env->shader_programme, "posmodif"), 1,
		env->pos);
	glDrawArrays(GL_TRIANGLES, 0, env->nbtr * 3);
	mlx_opengl_swap_buffers(env->win);
	return (0);
}

void	resizeaux(float xd, float yd, float zd, t_env *env)
{
	env->maxx -= xd;
	env->minx -= xd;
	env->maxy -= yd;
	env->miny -= yd;
	env->maxz -= zd;
	env->minz -= zd;
}

void	resize(float *p, int size, t_env *env)
{
	int		i;
	float	resizediv;
	float	xd;
	float	yd;
	float	zd;

	i = -1;
	resizediv = 0;
	xd = (env->maxx + env->minx) / 2;
	yd = (env->maxy + env->miny) / 2;
	zd = (env->maxz + env->minz) / 2;
	resizeaux(xd, yd, zd, env);
	resizediv = (resizediv > env->maxx) ? resizediv : env->maxx;
	resizediv = (resizediv > env->maxy) ? resizediv : env->maxy;
	resizediv = (resizediv > env->maxz) ? resizediv : env->maxz;
	if ((resizediv = resizediv * 1.5) == 0)
		ft_error("dafuq23347");
	while (i + 3 < size)
	{
		p[i + 1] = (p[i + 1] - xd) / resizediv;
		p[i + 2] = (p[i + 2] - yd) / resizediv;
		p[i + 3] = (p[i + 3] - zd) / resizediv;
		i += 9;
	}
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc < 2)
		ft_error("pas de .obj");
	env.textname = NULL;
	if (argc > 2)
		env.textname = argv[2];
	env.nbtr = 0;
	env.max = 0;
	env.min = 0;
	env.pause = 0;
	env.textenable = 0;
	env.texte = 0;
	bzero(env.pos, 3);
	env.ptrs = objreader(argv[1], &env);
	resize(env.ptrs, env.nbtr * 27, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_opengl_window(env.mlx, 1600, 1200, "scop");
	mlx_opengl_window_set_context(env.win);
	initshadder(&env);
	mlx_hook(env.win, 2, 1, key_hook, &env);
	mlx_loop_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
}

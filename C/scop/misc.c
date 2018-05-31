/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 02:06:02 by gfournie          #+#    #+#             */
/*   Updated: 2017/08/25 02:06:04 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void	initshadderbuffer(t_env *env)
{
	env->vbo = 0;
	glGenBuffers(1, &env->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER,
		27 * env->nbtr * sizeof(float), env->ptrs, GL_STATIC_DRAW);
	env->vao = 0;
	glGenVertexArrays(1, &env->vao);
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		9 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE,
		9 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
	glBindVertexArray(env->vao);
}

void	initshaddertext(t_env *env)
{
	GLuint tex_2d;

	tex_2d = loadtex(env->textname);
	if (0 == tex_2d)
		ft_error("dafuq4356");
}

void	initshadder(t_env *env)
{
	const char	*vertex_shader = readf("vertex_shader.vs");
	const char	*fragment_shader = readf("fragment_shader.fs");
	GLuint		vs;
	GLuint		fs;

	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	checkcompileshader(vs);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);
	checkcompileshader(fs);
	env->shader_programme = glCreateProgram();
	glAttachShader(env->shader_programme, fs);
	glAttachShader(env->shader_programme, vs);
	glLinkProgram(env->shader_programme);
	glUseProgram(env->shader_programme);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LESS);
	initshadderbuffer(env);
	if (env->textname != NULL)
		initshaddertext(env);
}

char	*readf(const char *name)
{
	struct stat	st;
	int			fd;
	char		*r;

	if ((fd = open(name, O_RDONLY)) < 0)
		ft_error("readf fail");
	fstat(fd, &st);
	if ((r = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE | MAP_FILE, fd, 0))
		< 0)
		ft_error("readf fail 2");
	return (r);
}

void	checkcompileshader(GLuint id)
{
	int		rvalue;
	GLchar	log[10240];
	GLsizei	length;

	glGetShaderiv(id, GL_COMPILE_STATUS, &rvalue);
	if (!rvalue)
	{
		fprintf(stderr, "Error in compiling the compute shader\n");
		glGetShaderInfoLog(id, 10239, &length, log);
		fprintf(stderr, "Compiler log:\n%s\n", log);
		exit(40);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:57:46 by gfournie          #+#    #+#             */
/*   Updated: 2017/07/26 17:57:47 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_H
# define LE_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "mlx/mlx_opengl.h"
# include <OpenGL/gl3.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <strings.h>
# include "SOIL2-master/incs/SOIL2.h"

# define ISWHITESPACEEND || *line == '\r' || *line == '\f' || *line == ' ')
# define ISWHITESPACE (*line == '\v' || *line == '\t' ISWHITESPACEEND
# define LIMIT 20000000

typedef struct		s_header
{
	unsigned char	file_marker1;
	unsigned char	file_marker2;
	unsigned int	bf_size;
	short			unused1;
	short			unused2;
	unsigned int	image_data_offset;
	unsigned int	bi_size;
	int				width;
	int				height;
	short			planes;
	short			bit_pix;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_xpels_per_meter;
	int				bi_ypels_per_meter;
	unsigned int	bi_clrused;
	unsigned int	bi_clr_important;
}					t_header;

typedef	struct		s_vec
{
	float				x;
	float				y;
	float				z;
}					t_vec;

typedef	struct		s_read
{
	float		*r;
	float		*vn;
	float		*v;
	float		*vt;
	int			i;
	int			j;
	int			k;
}					t_read;

typedef struct		s_tr
{
	float				points[9];
	t_vec				u;
	t_vec				v;
	float				d;
	float				uu;
	float				uv;
	float				vv;
	t_vec				n;
	struct s_tr			*next;
}					t_tr;

typedef	struct		s_env
{
	void				*mlx;
	void				*win;
	int					nbtr;
	float				*ptrs;
	float				max;
	float				maxx;
	float				maxy;
	float				maxz;
	float				min;
	float				minx;
	float				miny;
	float				minz;
	GLuint				vbo;
	GLuint				vbo2;
	GLuint				vao;
	GLuint				shader_programme;
	char				*textname;
	float				textenable;
	int					texte;
	float				pos[3];
	int					pause;
}					t_env;

float				ft_fatoi(char *s);
float				*objreader(char *name, t_env *env);
char				*readf(const char *name);
void				checkcompileshader(GLuint id);
void				initshadder(t_env *env);
void				newtriangleobj(char *line, t_read *r, int *j);
int					loadtex(char *name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 19:06:56 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/07 19:07:00 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_H
# define LE_H

# include <unistd.h>
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <pthread.h>

# define T_D long long long long long double

typedef struct	s_env
{
	char	type;
	int		h;
	int		l;
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		sizel;
	int		i;
	double	z;
	double	x;
	double	y;
	int		exit;
	double	jx;
	double	jy;
	int		jc;
	int		it;
}				t_env;

int				autrefonction(int x, int y, t_env *e);
void			put_pixel(t_env *pos, register int x, register int y,\
int color);
int				pixeluse(t_env *pos, register int x, register int y);
void			fougere(t_env *e);
void			julia(t_env *e, register int h, register int l);
float			modulo(register float x, register float y);
void			mandel(t_env *e, register int h, register int l);
void			newton(t_env *e, register int h, register int l);
void			pinit(t_env *e);
void			*t_5(void *e);
void			*t_4(void *e);
void			*t_3(void *e);
void			*t_2(void *e);
void			key2(int keycode, t_env *e);
void			fin(t_env *e);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 19:06:56 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/07 19:07:00 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline void		put_pixel(t_env *pos, register int x, register int y, int color)
{
	register unsigned char	color1;
	register unsigned char	color2;
	register unsigned char	color3;
	register int			img_size;

	img_size = pos->l * pos->h * pos->bpp / 8;
	if (x < 0 || y < 0 || y * pos->sizel + x * pos->bpp / 8 > img_size
	|| x >= pos->sizel / (pos->bpp / 8) || y >= img_size / pos->sizel)
		return ;
	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	pos->addr[y * pos->sizel + x * pos->bpp / 8] = color1;
	pos->addr[y * pos->sizel + x * pos->bpp / 8 + 1] = color2;
	pos->addr[y * pos->sizel + x * pos->bpp / 8 + 2] = color3;
}

inline int		pixeluse(t_env *pos, register int x, register int y)
{
	register int	img_size;

	img_size = pos->l * pos->h * pos->bpp / 8;
	if (x < 0 || y < 0 || y * pos->sizel + x * pos->bpp / 8 > img_size
	|| x >= pos->sizel / (pos->bpp / 8) || y >= img_size / pos->sizel)
		return (0);
	if (pos->addr[y * pos->sizel + x * pos->bpp / 8] != 0
		|| pos->addr[y * pos->sizel + x * pos->bpp / 8 + 1] != 0
		|| pos->addr[y * pos->sizel + x * pos->bpp / 8 + 2] != 0)
		return (1);
	return (0);
}

inline float	modulo(register float x, register float y)
{
	return (sqrt((x * x) + (y * y)));
}

void			fin(t_env *e)
{
	e->exit = 0;
	write(1, "./fractol j ou n ou m\n", 22);
	write(1, "(seulement la premiere lettre importe)\n", 39);
	exit(0);
}

int				autrefonction(int x, int y, t_env *e)
{
	if (e->jc)
	{
		e->jx = ((float)(x - e->l / 2) / (float)(e->l));
		e->jy = ((float)(y - e->h / 2) / (float)(e->h));
	}
	return (0);
}

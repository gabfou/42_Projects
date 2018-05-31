/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 23:17:07 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/12 23:19:25 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline int	mandelit(register int i)
{
	register unsigned char	color1;
	register unsigned char	color2;
	register unsigned char	color3;
	register int			col;

	col = 0x000000;
	color1 = ((col) >> 0);
	color2 = ((col) >> 8);
	color3 = ((col) >> 16);
	color1 = color1 + i;
	color2 = color2 + i;
	color3 = color3 + i;
	col = (color3 << 16) | (color2 << 8) | (color1 << 0);
	return (col);
}

inline void	mandel2(register int x, register int y, t_env *e,\
register int i)
{
	register long double	x2;
	register long double	y2;
	register long double	tmp;
	register long double	x3;
	register long double	y3;

	x3 = (x - e->l / 2) * e->z + (e->x);
	y3 = (y - e->h / 2) * e->z + (e->y);
	x2 = 0;
	y2 = 0;
	while (modulo(x2, y2) <= 2 && ++i < e->it)
	{
		tmp = (x2 * x2) - (y2 * y2) + x3;
		y2 = 2 * x2 * y2 + y3;
		x2 = tmp;
	}
	put_pixel(e, x, y, mandelit(i));
}

void		mandel(t_env *e, register int h, register int l)
{
	register int	x;
	register int	y;

	y = -1 + h;
	while (++y < e->h / 4 + h)
	{
		x = -1 + l;
		while (++x < e->l / 2 + l)
			mandel2(x, y, e, -1);
	}
}

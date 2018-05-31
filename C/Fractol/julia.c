/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:53:05 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/08 19:53:08 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline int	juliait(register int col)
{
	register unsigned char	color1;
	register unsigned char	color2;
	register unsigned char	color3;

	color1 = ((col) >> 0);
	color2 = ((col) >> 8);
	color3 = ((col) >> 16);
	col = (++color3 << 16) | (++color2 << 8) | (++color1 << 0);
	return (col);
}

inline void	julia2(register int x, register int y, t_env *e)
{
	register double	x2;
	register double	y2;
	register int	col;
	register int	i;
	register double	tmp;

	x2 = (x - e->l / 2) * e->z + (e->x);
	y2 = (y - e->h / 2) * e->z + (e->y);
	col = 0x000000;
	i = 0;
	while (modulo(x2, y2) <= 2 && ++i < e->it)
	{
		tmp = (x2 * x2) - (y2 * y2) - e->jx;
		y2 = 2 * x2 * y2 - e->jy;
		x2 = tmp;
		col = juliait(col);
	}
	put_pixel(e, x, y, col);
}

void		julia(t_env *e, register int h, register int l)
{
	register int	x;
	register int	y;

	y = -1 + h;
	while (++y < e->h / 4 + h)
	{
		x = -1 + l;
		while (++x < e->l / 2 + l)
			julia2(x, y, e);
	}
}

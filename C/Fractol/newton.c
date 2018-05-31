/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 12:47:16 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/15 12:47:19 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

inline int	newtonit(register long double x2, register long double y2)
{
	if (x2 > 0.0)
		return (0xFF0000);
	else
	{
		if ((x2 < -0.3) && (y2 > 0.0))
			return (0x00FF00);
		else
			return (0x0000FF);
	}
}

inline void	newton2(register int x, register int y, t_env *e)
{
	register long double	x2;
	register long double	y2;
	register long double	tmp;
	register int			i;
	register long double	d;

	x2 = (x - e->l / 2) * e->z + (e->x);
	y2 = (y - e->h / 2) * e->z + (e->y);
	i = -1;
	while (++i < e->it)
	{
		d = 3.0 * ((x2 * x2 - y2 * y2) * \
		(x2 * x2 - y2 * y2) + 4.0 * x2 * x2 * y2 * y2);
		tmp = (2.0 / 3.0) * x2 + (x2 * x2 - y2 * y2) / d;
		y2 = (2.0 / 3.0) * y2 - 2.0 * x2 * y2 / d;
		x2 = tmp;
	}
	put_pixel(e, x, y, newtonit(x2, y2));
}

void		newton(t_env *e, register int h, register int l)
{
	register int	x;
	register int	y;

	y = -1 + h;
	while (++y < e->h / 4 + h)
	{
		x = -1 + l;
		while (++x < e->l / 2 + l)
			newton2(x, y, e);
	}
}

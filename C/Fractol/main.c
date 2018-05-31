/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 22:25:43 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/16 22:25:48 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void	init(t_env *e, char *s)
{
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_t t5;

	e->type = s[0];
	e->i = 100;
	e->l = 1280;
	e->h = 800;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->l, e->h, "fractol");
	e->img = mlx_new_image(e->mlx, e->l, e->h);
	e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizel), &(e->endian));
	e->z = 0.008;
	e->x = 0;
	e->y = 0;
	e->exit = 1;
	e->jx = 0.0986;
	e->jy = 0.65186;
	e->jc = 1;
	pthread_create(&t2, NULL, t_2, e);
	pthread_create(&t3, NULL, t_3, e);
	pthread_create(&t4, NULL, t_4, e);
	pthread_create(&t5, NULL, t_5, e);
	pinit(e);
}

int		loop_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_do_sync(e->mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 || button == 5)
	{
		e->z *= 1.1;
		e->x = e->x + (x - (e->l / 2)) * e->z;
		e->y = e->y + (y - (e->h / 2)) * e->z;
	}
	if (button == 2 || button == 4)
	{
		e->z *= 0.9;
		e->x = e->x + (x - (e->l / 2)) * e->z;
		e->y = e->y + (y - (e->h / 2)) * e->z;
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		e->exit = 0;
		system ("killall afplay");
		exit(0);
	}
	key2(keycode, e);
	if (keycode == 78 && e->it > 1)
		e->it--;
	if (keycode == 67)
		e->it += 10;
	if (keycode == 75 && e->it > 10)
		e->it -= 10;
	if (keycode == 12)
	{
		if (e->jc)
			e->jc = 0;
		else
			e->jc = 1;
	}
	if (keycode == 84)
		e->y += 10 * e->z;
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc > 1)
	{
		init(&e, argv[1]);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook (e.win, mouse_hook, &e);
		mlx_hook(e.win, 6, 1 << 7, autrefonction, &e);
		mlx_loop_hook(e.mlx, loop_hook, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		write(1, "./fractol j ou n ou m\n", 22);
		write(1, "(seulement la premiere lettre importe)\n", 39);
	}
	e.exit = 0;
	return (0);
}

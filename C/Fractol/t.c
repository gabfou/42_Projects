/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 11:38:43 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/13 11:38:56 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void *t_5(void *e)
{
	while (((t_env*)e)->exit)
	{
		if ((((t_env*)e))->type == 'j')
			julia(((t_env*)e), 0, 0);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), 0, 0);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), 0, 0);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_2(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), 0, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), 0, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), 0, ((t_env*)e)->l / 2);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_3(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), ((t_env*)e)->h / 4, 0);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), ((t_env*)e)->h / 4, 0);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), ((t_env*)e)->h / 4, 0);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_4(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
	}
	pthread_exit(NULL);
	return (NULL);
}

void key2(int keycode, t_env *e)
{
	if (keycode == 126)
		e->z *= 1.1;
	if (keycode == 125)
		e->z *= 0.9;
	if (keycode == 91)
		e->y -= 10 * e->z;
	if (keycode == 88)
		e->x += 10 * e->z;
	if (keycode == 86)
		e->x -= 10 * e->z;
	if (keycode == 13)
	{
		e->z = 0.008;
		e->x = 0;
		e->y = 0;
	}
	if (keycode == 38)
		e->type = 'j';
	if (keycode == 45)
		e->type = 'n';
	if (keycode == 46)
		e->type = 'm';
	if (keycode == 69)
		e->it++;
}

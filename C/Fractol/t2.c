/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 14:54:25 by gfournie          #+#    #+#             */
/*   Updated: 2015/05/15 14:54:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

void *t_6(void *e)
{
	while (((t_env*)e)->exit)
	{
		if ((((t_env*)e))->type == 'j')
			julia(((t_env*)e), ((t_env*)e)->h / 2, 0);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), ((t_env*)e)->h / 2, 0);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), ((t_env*)e)->h / 2, 0);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_7(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), ((t_env*)e)->h / 2, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), ((t_env*)e)->h / 2, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), ((t_env*)e)->h / 2, ((t_env*)e)->l / 2);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_8(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), 3 * ((t_env*)e)->h / 4, 0);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), 3 * ((t_env*)e)->h / 4, 0);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), 3 * ((t_env*)e)->h / 4, 0);
	}
	pthread_exit(NULL);
	return (NULL);
}

void *t_9(void *e)
{
	while (((t_env*)e)->exit)
	{
		if (((t_env*)e)->type == 'j')
			julia(((t_env*)e), 3 * ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'm')
			mandel(((t_env*)e), 3 * ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
		if (((t_env*)e)->type == 'n')
			newton(((t_env*)e), 3 * ((t_env*)e)->h / 4, ((t_env*)e)->l / 2);
	}
	pthread_exit(NULL);
	return (NULL);
}

void pinit(t_env *e)
{
	pthread_t t6;
	pthread_t t7;
	pthread_t t8;
	pthread_t t9;

	if (e->type != 'n' && e->type != 'j' && e->type != 'm')
		fin(e);
	if (e->type == 'n')
		system("afplay winter.mp3 &");
	if (e->type == 'j')
		system("afplay rolmain.mp3 &");
	if (e->type == 'm')
		system("afplay rolwin.mp3 &");
	if (((t_env*)e)->type == 'j')
		e->it = 256;
	if (((t_env*)e)->type == 'n')
		e->it = 64;
	if (((t_env*)e)->type == 'm')
		e->it = 256;
	pthread_create(&t6, NULL, t_6, e);
	pthread_create(&t7, NULL, t_7, e);
	pthread_create(&t8, NULL, t_8, e);
	pthread_create(&t9, NULL, t_9, e);
}

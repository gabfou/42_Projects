/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:13:37 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/11 20:13:38 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline int	ft_freelittlefound(void *ptr, t_p *p, t_p *before, t_p **begin)
{
	long int i;

	i = (ptr - p->begin) / p->size_chunk;
	if (i - 1 >= 0 && p->chunk[i - 1] == 1)
		return (0);
	while (i >= 0 && p->chunk[i] != 2 && i < NBC)
		p->chunk[i++] = 0;
	p->chunk[i] = 0;
	i = 0;
	while (i < NBC && p->chunk[i] == 0)
		i++;
	if (i == NBC)
	{
		if (before == NULL)
			*begin = p->next;
		else
			before->next = p->next;
		munmap(p->begin, p->size);
	}
	return (1);
}

static int	freelittle(void *ptr, t_p **p)
{
	t_p		*before;
	t_p		*tmp;

	before = NULL;
	tmp = *p;
	while (tmp)
	{
		if (ptr >= tmp->begin && ptr <= tmp->begin + (tmp->size_chunk * NBC))
			return (ft_freelittlefound(ptr, tmp, before, p));
		before = tmp;
		tmp = tmp->next;
	}
	return (0);
}

static int	freebig(void *ptr)
{
	t_b		*tmp;
	void	*tmp2;

	tmp = g_g.large;
	if (tmp && tmp->begin == ptr)
	{
		g_g.large = tmp->next;
		munmap(ptr, tmp->size);
		pthread_mutex_unlock(&g_mutex);
		return (1);
	}
	while (tmp && tmp->next)
	{
		if (tmp->next->begin == ptr)
		{
			tmp2 = tmp->next->next;
			munmap(ptr, tmp->next->size);
			tmp->next = tmp2;
			pthread_mutex_unlock(&g_mutex);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		ft_free(void *ptr)
{
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mutex);
	if (freebig(ptr))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (freelittle(ptr, &(g_g.small)) == 0)
		freelittle(ptr, &(g_g.tiny));
	ptr = NULL;
	pthread_mutex_unlock(&g_mutex);
}

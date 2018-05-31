/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:44:52 by gfournie          #+#    #+#             */
/*   Updated: 2017/07/22 17:44:54 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_g				g_g = {NULL, NULL, NULL};
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static t_p	*ft_newpage(size_t size, size_t size_chunk)
{
	t_p		*new;
	void	*ptr;
	void	*addr;

	if ((ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	addr = ptr + size - sizeof(t_p);
	new = (t_p*)addr;
	new->begin = ptr;
	new->size = size;
	new->sizereal = size - sizeof(t_p);
	new->size_chunk = size_chunk;
	ft_bzero(new->chunk, NBC);
	return (new);
}

static t_p	*ft_newpagehelper(size_t size)
{
	if (size > M)
		return (NULL);
	if (size > N)
		return (ft_newpage(MT, MC));
	return (ft_newpage(NT, NC));
}

static void	*ft_trytofit(size_t size, t_p *p)
{
	size_t	sizetmp;
	size_t	i;

	if (size > p->sizereal)
		return (NULL);
	i = -1;
	sizetmp = 0;
	while (++i < NBC)
	{
		sizetmp = (p->chunk[i] == 0) ? sizetmp + 1 : 0;
		if (sizetmp * p->size_chunk >= size)
		{
			p->chunk[i] = 2;
			while (--sizetmp != 0)
				p->chunk[--i] = 1;
			return (p->begin + (i * p->size_chunk));
		}
	}
	return (NULL);
}

static void	*ft_addaddrin(size_t size, t_p **p)
{
	t_p		*tmp;
	void	*ptr;

	ptr = NULL;
	if (*p == NULL)
	{
		*p = ft_newpagehelper(size);
		if (*p == NULL)
			return (NULL);
		return (ft_trytofit(size, *p));
	}
	tmp = *p;
	while (tmp && (ptr = ft_trytofit(size, tmp)) == NULL)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		tmp = ft_newpagehelper(size);
		if (tmp == NULL)
			return (NULL);
		tmp->next = (*p);
		*p = tmp;
		return (ft_trytofit(size, tmp));
	}
	return (ptr);
}

void		*ft_malloc(size_t size)
{
	void	*ptr;
	size_t	tmp;

	if (size == 0)
		size = 1;
	pthread_mutex_lock(&g_mutex);
	if (size > M)
	{
		tmp = (size + sizeof(t_b));
		tmp = (tmp % getpagesize() != 0)
			? tmp + getpagesize() - (tmp % getpagesize()) : tmp;
		if ((ptr = mmap(NULL, tmp, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
			return (returnmutexsafe(NULL));
		ft_addbigp(tmp, ptr, ptr + size, size);
		return (returnmutexsafe(ptr));
	}
	ptr = (size > N) ? ft_addaddrin(size, &(g_g.small))
		: ft_addaddrin(size, &(g_g.tiny));
	return (returnmutexsafe(ptr));
}

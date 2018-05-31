/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:48:25 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/12 17:48:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_realloctrytofit(void *ptr, t_p *found, size_t size)
{
	long int i;
	long int j;

	i = (ptr - found->begin) / found->size_chunk - 1;
	if ((i >= 0 && found->chunk[i] == 1))
		return (NULL);
	j = 0;
	while (found->chunk[++i] != 2 && (size_t)(++j) < size)
		;
	if ((size_t)(j++) == size)
	{
		ft_remplitjusqua(&(found->chunk[i]), 0, 0, 2);
		return (ptr);
	}
	i++;
	while (found->chunk[++i] == 0 && (size_t)(++j) < size)
		;
	if ((size_t)(j) == size)
	{
		i = (ptr - found->begin) / found->size_chunk;
		j = 0;
		ft_remplitjusqua(&(found->chunk[i]), 1, 2, 2);
		return (ptr);
	}
	return (NULL);
}

static void	*ft_reallocfromlittle(void *ptr, size_t size, t_p **p, int *k)
{
	t_p			*before;
	t_p			*tmp;
	void		*ptr2;

	before = NULL;
	tmp = *p;
	while (tmp)
	{
		if (ptr >= tmp->begin && ptr <= tmp->begin + (tmp->size_chunk * NBC))
		{
			*k = 1;
			if (ft_realloctrytofit(ptr, tmp, size) == ptr)
				return (ptr);
			pthread_mutex_unlock(&g_mutex);
			ptr2 = ft_malloc(size);
			pthread_mutex_lock(&g_mutex);
			if (ptr2 == NULL || ft_freelittlefound(ptr, tmp, before, p) == 0)
				return (NULL);
			return (ptr2);
		}
		before = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

static void	*ft_reallocfromlittlebase(void *ptr, size_t size)
{
	void	*ptrret;
	int		i;

	i = 0;
	if ((ptrret = ft_reallocfromlittle(ptr, size, &(g_g.small), &i)) != NULL)
		return (ptrret);
	if ((ptrret = ft_reallocfromlittle(ptr, size, &(g_g.tiny), &i)) != NULL)
		return (ptrret);
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

static void	*ft_reallocfrombig(void *ptr, size_t size, t_b *b)
{
	long int	i;
	void		*ptrret;

	pthread_mutex_unlock(&g_mutex);
	ptrret = ft_malloc(size);
	pthread_mutex_lock(&g_mutex);
	if (ptr == NULL)
		return (returnmutexsafe(NULL));
	i = -1;
	while ((size_t)(++i) < size && (size_t)(i) < b->sizereal)
		((char*)(ptrret))[i] = ((char*)(b->begin))[i];
	munmap(ptr, b->size);
	return (ptrret);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_b		*tmp;
	void	*tmp2;

	tmp = g_g.large;
	if (!ptr)
		return (ft_malloc(size));
	pthread_mutex_lock(&g_mutex);
	if (tmp && tmp->begin == ptr)
	{
		g_g.large = tmp->next;
		return (returnmutexsafe(ft_reallocfrombig(ptr, size, tmp)));
	}
	while (tmp && tmp->next)
	{
		if (tmp->next->begin == ptr)
		{
			tmp2 = tmp->next->next;
			ptr = ft_reallocfrombig(ptr, size, tmp->next);
			tmp->next = tmp2;
			return (returnmutexsafe(ptr));
		}
		tmp = tmp->next;
	}
	return (returnmutexsafe(ft_reallocfromlittlebase(ptr, size)));
}

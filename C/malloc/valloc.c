/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 23:36:59 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/14 23:37:01 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_valloc(size_t size)
{
	void	*ptr;
	int		tmp;

	pthread_mutex_lock(&g_mutex);
	if (size == 0)
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	tmp = (size + sizeof(t_b));
	tmp = (tmp % getpagesize() != 0)
		? tmp + getpagesize() - (tmp % getpagesize()) : tmp;
	if ((ptr = mmap(NULL, tmp, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (returnmutexsafe(NULL));
	ft_addbigp(tmp, ptr, ptr + size, size);
	return (returnmutexsafe(ptr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 22:55:23 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/14 22:55:26 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline void	*returnmutexsafe(void *s)
{
	pthread_mutex_unlock(&g_mutex);
	return (s);
}

inline void	ft_remplitjusqua(char *s, char c, char end, char limit)
{
	long int i;

	i = -1;
	while (s[++i] != limit)
		s[i] = c;
	s[i] = end;
}

inline void	ft_addbigp(size_t size, void *ptr, void *addr, size_t sizereal)
{
	t_b	*new;

	new = (t_b*)addr;
	new->begin = ptr;
	new->size = size;
	new->sizereal = sizereal;
	new->next = g_g.large;
	g_g.large = new;
}

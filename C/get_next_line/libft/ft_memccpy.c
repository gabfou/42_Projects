/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:09:21 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 14:01:36 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int			i;
	char		*s1;
	const char	*s2;

	i = -1;
	s1 = dst;
	s2 = src;
	while (++i < (int)n && s2[i] != (char)c)
		s1[i] = s2[i];
	if (i == (int)n)
		return (NULL);
	return ((void*)&s1[i + 1]);
}

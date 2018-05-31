/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:45:39 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/16 16:31:29 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*s1;
	const char	*s2;

	i = -1;
	s1 = dst;
	s2 = src;
	while (++i < (int)n)
		s1[i] = s2[i];
	return (dst);
}

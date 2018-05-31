/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:24:18 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:58:21 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*s1;
	const char	*s2;
	char		s3[len];

	i = -1;
	s1 = dst;
	s2 = src;
	while (++i < (int)len)
		s3[i] = s2[i];
	i = -1;
	while (++i < (int)len)
		s1[i] = s3[i];
	return (dst);
}

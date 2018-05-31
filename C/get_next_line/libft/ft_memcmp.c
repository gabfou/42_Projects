/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:34:21 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:59:37 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]
		&& i < (n - 1))
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

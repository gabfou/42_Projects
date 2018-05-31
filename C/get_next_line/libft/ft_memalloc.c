/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:09:55 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/06 20:33:18 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *r;

	r = NULL;
	r = malloc(sizeof(r) * size);
	if (r != NULL)
		memset(r, '\0', size);
	return (r);
}

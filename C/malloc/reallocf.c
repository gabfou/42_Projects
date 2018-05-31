/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 23:13:03 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/14 23:13:04 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_reallocf(void *ptr, size_t size)
{
	void *ptr2;

	ptr2 = ft_realloc(ptr, size);
	if (ptr2 == NULL)
		ft_free(ptr);
	return (ptr2);
}

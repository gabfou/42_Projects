/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:13:37 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/11 20:13:38 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	return (ft_calloc(count, size));
}

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}

void	*valloc(size_t size)
{
	return (ft_valloc(size));
}

void	*realloc(void *ptr, size_t size)
{
	return (ft_realloc(ptr, size));
}

void	*reallocf(void *ptr, size_t size)
{
	return (ft_reallocf(ptr, size));
}

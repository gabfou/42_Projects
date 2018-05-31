/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:41:07 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:50:07 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	s = NULL;
	s = malloc(sizeof(s) * size);
	if (s == NULL)
		return (s);
	i = -1;
	while (++i < (int)size)
		s[i] = '\0';
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:23:46 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/09 20:44:24 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = NULL;
	while (s[i])
	{
		if (c == s[i])
			s2 = (char*)&s[i];
		i++;
	}
	if (c == s[i])
		return ((char*)&s[i]);
	return (s2);
}

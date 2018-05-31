/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:01:17 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/05 16:08:59 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		c;
	int		r;

	if (s2[0] == '\0')
		return ((char*)s1);
	i = -1;
	while (s1[++i] != 0 && i < (int)n)
	{
		if (s1[i] == s2[0])
		{
			r = i;
			c = 0;
			while (s1[++r] == s2[++c] && s1[i] && r < (int)n)
			{
				if (c + 1 == ft_strlen(s2))
					return ((char*)&s1[i]);
			}
		}
	}
	return (NULL);
}

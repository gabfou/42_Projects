/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:01:17 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/08 21:12:59 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		c;
	int		r;

	if (to_find[0] == '\0')
		return ((char*)str);
	i = -1;
	while (str[++i] != 0)
	{
		if (str[i] == to_find[0])
		{
			r = i - 1;
			c = -1;
			while (str[++r] == to_find[++c] && str[r])
			{
				if (c + 1 == ft_strlen(to_find))
					return ((char*)&str[i]);
			}
		}
	}
	return (NULL);
}

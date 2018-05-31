/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:40:32 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:52:55 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r;

	i = -1;
	if (s)
		r = malloc(ft_strlen(s));
	if (s && f && r)
		while (s[++i])
			r[i] = f(i, s[i]);
	else
		return (NULL);
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:21:05 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:53:06 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*r;

	i = -1;
	r = NULL;
	if (s)
		r = malloc(ft_strlen(s));
	if (r && s && f)
		while (s[++i])
			r[i] = f(s[i]);
	else
		return (NULL);
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:06:50 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:47:43 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;
	int		j;

	s1 = NULL;
	s1 = malloc(sizeof(s) * (len + 1));
	if (s1 == NULL || s == NULL)
		return (s1);
	i = 0;
	while (i < (int)start)
		i++;
	j = -1;
	while (++j < (int)len)
		s1[j] = s[i++];
	s1[j] = 0;
	return (s1);
}

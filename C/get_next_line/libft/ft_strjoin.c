/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:14:36 by gfournie          #+#    #+#             */
/*   Updated: 2014/12/05 15:19:02 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = malloc(sizeof(s3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i++] = s2[j];
	s3[i] = '\0';
	return (s3);
}

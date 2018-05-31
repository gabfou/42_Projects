/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:00:53 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/10 13:51:46 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	init(int *i, int *j, const char *s, int *k)
{
	if (s == NULL)
		return (-1);
	i[0] = 0;
	j[0] = 0;
	while (s && s[i[0]] && (s[i[0]] == ' '
		|| s[i[0]] == '\t' || s[i[0]] == '\n'))
		i[0]++;
	while (s[j[0]] && s)
		j[0]++;
	if (j[0])
		j[0]--;
	k[0] = -1;
	while (s && s[j[0]] && (s[j[0]] == ' ' || s[j[0]] == '\t'
		|| s[j[0]] == '\n') && j[0] > 0)
		j[0]--;
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*c;
	int		j;
	int		k;

	if (init(&i, &j, s, &k) == -1)
		return (NULL);
	if (j == 1 || j <= i)
	{
		c = malloc(sizeof(c));
		if (c)
			c[0] = 0;
		return (c);
	}
	c = malloc(sizeof(c) * (j - i + 2));
	if (c == NULL || s == NULL)
		return (NULL);
	j = j - i--;
	while (++k < j + 1 && s[i + 1] && s[k])
		c[k] = s[++i];
	if (k >= 0)
		c[k] = '\0';
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:38:23 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/08 23:20:27 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_compteur(char const *s, char c)
{
	int i;
	int r;

	i = -1;
	r = 0;
	while (s[i + 1] && s[i + 1] == c)
		i++;
	if (s[i + 1])
		r++;
	else
		return (1);
	while (s[++i] && s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			r++;
	}
	return (r + 1);
}

static int		ft_compteur2(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

static void		place(char const **s, int *i, char *c, int *j)
{
	j[0] = -1;
	while (s[0][i[0]] && s[0][i[0]] == c[0])
		i[0]++;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	if (c == 0 || s == NULL)
		return (NULL);
	r = malloc(sizeof(char*) * ft_compteur(s, c));
	i = 0;
	k = -1;
	while ((++k + 1) < ft_compteur(s, c) && s[i] && r && s)
	{
		place(&s, &i, &c, &j);
		r[k] = malloc(sizeof(char*) * ft_compteur2(&s[i], c));
		if (r[k] == NULL)
			return (NULL);
		while (s[i] && s[i] != c)
			r[k][++j] = s[i++];
		r[k][++j] = 0;
	}
	if (r)
		r[k] = NULL;
	return (r);
}

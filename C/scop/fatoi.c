/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 05:20:56 by gfournie          #+#    #+#             */
/*   Updated: 2017/08/03 05:21:02 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le.h"

#define NORME int i = 0;float k = 0

float	fatoi_aux(char *str, float *si, float *di)
{
	NORME;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	if (*si == 0)
		*si = (str[i - 1] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	*di = i;
	return (k);
}

float	ft_fatoi(char *s)
{
	float	d1;
	float	d2;
	int		i;
	float	si;
	float	di;

	i = 0;
	d2 = 0;
	si = 0;
	d1 = fatoi_aux(s, &si, &di);
	while (s[i] && s[i] != '.')
		i++;
	di = 0;
	if (s[i] && s[i] == '.')
		d2 = fatoi_aux(&s[i + 1], &si, &di);
	while (di > 0)
	{
		d2 = d2 / 10;
		di--;
	}
	return (si * (d1 + d2));
}

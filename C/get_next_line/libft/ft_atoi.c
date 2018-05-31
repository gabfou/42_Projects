/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:26:05 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/08 21:26:05 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int sign;
	int i;

	if (str == NULL)
		return (0);
	res = 0;
	sign = 1;
	i = -1;
	while ((str[i + 1] == ' ') || (str[i + 1] == '\n')
	|| (str[i + 1] == '\t') || (str[i + 1] == '\v')
	|| (str[i + 1] == '\r') || (str[i + 1] == '\f'))
		i++;
	if (str[i + 1] == '-')
		sign = -1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
		i++;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (sign * res);
	}
	return (sign * res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:37:01 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/09 18:48:47 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int power)
{
	int i;

	if (power < 0)
		return (0);
	i = nb;
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	if (nb == -1)
	{
		if (power % 2 == 0)
			return (1);
		else
			return (-1);
	}
	while (power != 1)
	{
		nb = nb * i;
		power--;
	}
	return (nb);
}

static void	init(int *n, int *t, int *i, int *sign)
{
	i[0] = 1;
	if (n[0] < 0)
	{
		sign[0] = 1;
		i[0]++;
	}
	else
	{
		sign[0] = 0;
		n[0] = n[0] * -1;
	}
	t[0] = n[0];
	while (t[0] < -9)
	{
		i[0]++;
		t[0] = t[0] / 10;
	}
}

char		*ft_itoa(int n)
{
	int		t;
	int		i;
	char	*s;
	int		sign;

	init(&n, &t, &i, &sign);
	s = malloc(i + 1);
	if (s == NULL)
		return (s);
	t = -1;
	if (sign == 1)
	{
		s[++t] = '-';
		i--;
	}
	while (i > 0)
	{
		s[++t] = ((n / ft_power(10, i - 1)) * -1) + 48;
		n = n - ((n / ft_power(10, i - 1)) * ft_power(10, i - 1));
		i--;
	}
	s[++t] = 0;
	return (s);
}

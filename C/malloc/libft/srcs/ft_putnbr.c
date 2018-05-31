/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:32:17 by gudepard          #+#    #+#             */
/*   Updated: 2013/11/21 20:37:09 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	ln;
	int			len;
	long int	p10;
	char		c;

	ln = n;
	len = 1;
	p10 = 1;
	while (n / (p10 *= 10))
		++len;
	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
	}
	while ((p10 /= 10) > 0)
	{
		c = '0' + ABS(ln / p10) % 10;
		write(1, &c, 1);
	}
}

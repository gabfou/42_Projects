/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 22:14:57 by gfournie          #+#    #+#             */
/*   Updated: 2014/11/05 16:12:47 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr((n - (n % 10)) / 10);
	ft_putchar((n % 10) + 48);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 23:31:48 by gfournie          #+#    #+#             */
/*   Updated: 2017/09/12 23:31:50 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			ft_putptr(void *ptr)
{
	size_t	n;
	char	c;

	n = (size_t)ptr;
	if (n >= 16)
		ft_putptr((void*)(n / 16));
	else
		write(1, "0x", 2);
	n %= 16;
	if (n >= 10)
		c = 'A' + n - 10;
	else
		c = '0' + n;
	write(1, &c, 1);
}

size_t			printchunck(t_p *p)
{
	int		i;
	void	*tmp;
	void	*tmp2;
	size_t	ret;

	i = -1;
	ret = 0;
	while (++i < NBC)
	{
		if (p->chunk[i] > 0)
		{
			tmp = p->begin + (i * p->size_chunk);
			ft_putptr(tmp);
			ft_putstr(" - ");
			while (p->chunk[i] != 2)
				i++;
			tmp2 = p->begin + ((i + 1) * p->size_chunk);
			ft_putptr(tmp2);
			ft_putstr(" : ");
			ret = tmp2 - tmp;
			ft_putnbr(ret);
			ft_putendl(" octets");
		}
	}
	return (ret);
}

void			show_alloc_memend(int total)
{
	t_b *tmp;

	tmp = g_g.large;
	while (tmp)
	{
		ft_putstr("LARGE : ");
		ft_putptr(tmp->begin);
		ft_putstr("\n");
		ft_putptr(tmp->begin);
		ft_putstr(" - ");
		ft_putptr(tmp->begin + tmp->sizereal);
		ft_putstr(" : ");
		ft_putnbr(tmp->sizereal);
		ft_putendl(" octets");
		total += tmp->sizereal;
		tmp = tmp->next;
	}
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
}

void			show_alloc_mem(void)
{
	t_p *tmp2;
	int	total;

	total = 0;
	tmp2 = g_g.tiny;
	while (tmp2)
	{
		ft_putstr("TINY : ");
		ft_putptr(tmp2->begin);
		ft_putstr("\n");
		total += printchunck(tmp2);
		tmp2 = tmp2->next;
	}
	tmp2 = g_g.small;
	while (tmp2)
	{
		ft_putstr("SMALL : ");
		ft_putptr(tmp2->begin);
		ft_putstr("\n");
		total += printchunck(tmp2);
		tmp2 = tmp2->next;
	}
	show_alloc_memend(total);
}

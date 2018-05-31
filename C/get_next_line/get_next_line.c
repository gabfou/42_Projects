/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:16:51 by gfournie          #+#    #+#             */
/*   Updated: 2015/01/15 19:13:18 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int	verif(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

static char	*decoupator(char *s, int *t2, char **indic)
{
	int i;

	i = 0;
	t2[0] = (s[0]) ? 1 : 0;
	if (!s[0])
		return (s);
	while (s[i] && s[i] != '\n')
		i++;
	indic[0] = malloc(sizeof(indic[0]) * (i + 1));
	i = -1;
	while (s[++i] && s[i] != '\n')
		indic[0][i] = s[i];
	indic[0][i + 1] = 0;
	i = (s[i] == '\n') ? i + 1 : i;
	return (strdup(&s[i]));
}

static char	*lectator(int const fd, char *s, char **indic, int *r2)
{
	char	buf[(BUFF_SIZE > 10000) ? 1 : BUFF_SIZE + 1];
	int		t;
	char	*r;
	char	*buf2;

	buf2 = malloc(sizeof(buf2) * (BUFF_SIZE + 1));
	if (!(r = malloc(sizeof(r))))
		return (NULL);
	r[0] = 0;
	if (s)
		r = s;
	if (verif(r) != 1)
		while ((t = read(fd, (BUFF_SIZE > 10000) ? buf2 : buf, BUFF_SIZE)))
		{
			if (t < 0)
				return (NULL);
			buf2[t] = 0;
			if (BUFF_SIZE <= 10000)
				buf[t] = 0;
			r = ft_strjoin(r, (BUFF_SIZE > 10000) ? buf2 : buf);
			t = -1;
			if (verif(r) == 1)
				break ;
		}
	return (decoupator(r, r2, indic));
}

static void	memorator(int const fd, int *i, char **indic, t_btree *tmp)
{
	static t_btree	*niark;
	t_btree			*niaf;

	niaf = (niark) ? niark : NULL;
	while (niark)
	{
		if (niark->fd == fd)
		{
			niark->item = lectator(fd, niark->item, indic, i);
			break ;
		}
		tmp = niark;
		niark = niark->right;
	}
	if (!niark)
	{
		if (!(niark = malloc(sizeof(niark))))
			return ;
		if (tmp)
			tmp->right = niark;
		niark->right = NULL;
		niark->fd = fd;
		niark->item = lectator(fd, NULL, indic, i);
	}
	niark = (niaf) ? niaf : niark;
}

int			get_next_line(int const fd, char **line)
{
	int				t;
	t_btree			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	t = 0;
	tmp = NULL;
	memorator(fd, &t, line, tmp);
	if (line[0] == NULL)
		return (-1);
	if (t == 0)
	{
		line[0] = malloc(sizeof(line[0]));
		line[0][0] = 0;
	}
	return (t);
}
